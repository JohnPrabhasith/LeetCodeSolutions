class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        dp = [[-1]*n for _ in range(m)]

        def returnAns(i, j, s, t):
            if i < 0 or j < 0:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            if s[i] == t[j]:
                dp[i][j] = 1 + returnAns(i-1, j-1, s, t)
            else:
                dp[i][j] = max(returnAns(i-1, j , s, t), returnAns(i, j-1, s, t))

            return dp[i][j]
        
        return returnAns(m-1, n-1, s, t)