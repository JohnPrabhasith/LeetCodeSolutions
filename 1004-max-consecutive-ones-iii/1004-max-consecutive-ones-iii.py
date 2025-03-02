class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        maxLen = float('-inf')
        l, r = 0, 0
        zeroes = 0

        while(r < len(nums)):
            if(nums[r] == 0):
                zeroes += 1
            if zeroes > k:
                while nums[l] != 0:
                    l += 1
                l += 1
                zeroes -= 1        
            r += 1
            maxLen = max(maxLen, r-l)
        return maxLen
        
        