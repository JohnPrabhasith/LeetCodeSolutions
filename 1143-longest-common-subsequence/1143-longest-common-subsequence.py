class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        # dp = [[-1]*(n) for _ in range(m)]
        dp = [[0]*(n+1) for _ in range(m+1)]

        def recursiveAns(i, j, s, t):
            if i < 0 or j < 0:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            if s[i] == t[j]:
                dp[i][j] = 1 + recursiveAns(i-1, j-1, s, t)
            else:
                dp[i][j] = max(recursiveAns(i-1, j , s, t), recursiveAns(i, j-1, s, t))

            return dp[i][j]
        
        def TabulationAns(m, n, s, t):
            for i in range(1,m+1):
                for j in range(1,n+1):
                    if s[i-1] == t[j-1]:
                        dp[i][j] = 1 + dp[i-1][j-1]
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            return dp[m][n]
        # return recursiveAns(m-1, n-1, s, t)
        return TabulationAns(m, n, s, t)