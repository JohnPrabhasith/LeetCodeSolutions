class Solution:
    def minPathSum(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        dp = [[None]*n for _ in range(m)]
        # dp[n-1][n-1] = arr[n-1][n-1]

        def solve(i, j):
            if i < 0 or j < 0:
                return float('inf')
            if  i == 0 and j == 0:
                return arr[i][j]
            if dp[i][j] is not None:
                return dp[i][j]

            up = solve(i - 1, j)  # Move up
            left = solve(i, j - 1)  # Move left
            
            dp[i][j] = arr[i][j] + min(up, left)
            return dp[i][j]

        return solve(m-1, n-1)