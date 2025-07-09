class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1]*(n+1)
        if m == 0 or n == 0:
            return 0
        # dp = [[1] * (n+1) for _ in range(m+1)]
        # def solve(i, j):
        #     if i >= m or j >= n:
        #         return 0
        #     if i == m-1 and j == n-1:
        #         return 1
        #     if dp[i][j] != 1: return dp[i][j]
        #     dp[i][j] = solve(i+1, j) + solve(i, j+1)
        #     return dp[i][j]
        # return solve(0, 0)


        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dp[j] = dp[j] + dp[j+1]
        return dp[0]