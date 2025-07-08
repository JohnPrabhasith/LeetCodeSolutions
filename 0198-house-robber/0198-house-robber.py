class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0]*(n+1)

        ## Approach 1
        # def recursive(n):
        #     if n < 0:
        #         return 0
        #     if dp[n] != 0:
        #         return dp[n]
        #     dp[n] = max(nums[n] + recursive(n-2), recursive(n-1))
        #     return dp[n]
        # return recursive(n-1)

        ##Approach 2
        if n == 0: return 0
        if n == 1: return nums[0]
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        return dp[-2]