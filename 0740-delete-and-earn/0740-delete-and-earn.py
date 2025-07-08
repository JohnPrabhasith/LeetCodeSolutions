from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        counter = Counter(nums)
        nums = sorted(list(set(nums)))
        n = len(nums)
        dp = [0]*(n+1)
        dp[1] = nums[0] * counter[nums[0]]

        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                dp[i+1] = max(nums[i] * counter[nums[i]] + dp[i - 1], dp[i])
            else:
                dp[i+1] = dp[i] + (nums[i] * counter[nums[i]])

        return dp[n]
