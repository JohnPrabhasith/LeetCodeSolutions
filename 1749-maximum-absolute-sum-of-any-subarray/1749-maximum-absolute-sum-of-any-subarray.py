class Solution(object):
    def maxAbsoluteSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = float('-inf')
        minSum = float('inf')
        minTemp = 0
        maxTemp = 0

        for num in nums:
            maxTemp += num
            minTemp += num

            maxSum = max(maxSum, maxTemp)
            minSum = min(minSum, minTemp)
            
            if(maxTemp < 0):
                maxTemp = 0
            if minTemp > 0:
                minTemp = 0
        
        return max(abs(maxSum), abs(minSum))