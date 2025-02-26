class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        diff = float('inf')

        for i, a in enumerate(nums):
            
            l, r = i+1, n-1

            while(l < r):
                threeSum = a + nums[l] + nums[r]
                currDiff = threeSum - target 

                if(abs(currDiff) < abs(diff - target)):
                    diff = threeSum
                if threeSum > target:
                    r -= 1
                elif threeSum < target:
                    l += 1
                else:
                    return threeSum
        return diff