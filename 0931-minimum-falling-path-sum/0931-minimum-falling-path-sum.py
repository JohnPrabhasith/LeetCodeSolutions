class Solution:
    def minFallingPathSum(self, dp: List[List[int]]) -> int:
        m, n = len(dp), len(dp[0])

        # dp = [[0] * (n) for _ in range(m)]
        # dp[-1] = dp[-1]
        for i in range(m-2, -1, -1):
            for j in range(n):
                if j == 0:
                    dp[i][j] += min(dp[i+1][j], dp[i+1][j+1])
                elif j == n-1:
                    dp[i][j] += min(dp[i+1][j-1], dp[i+1][j])
                else:
                    dp[i][j] += min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1])
        return min(dp[0])
