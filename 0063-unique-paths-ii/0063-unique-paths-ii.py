class Solution:
    def uniquePathsWithObstacles(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        if arr[m-1][n-1] != 0:
            return 0

        dp = [[None]*n for _ in range(m)]

        # for i in range(m-2, -1, -1):
        #     for j in range(n-2, -1, -1)

        def solve(i, j):
            if i == m-1 and j == n-1:
                return 1
            if i >= m or j >= n:
                return 0
            if dp[i][j] is not None:
                return dp[i][j]
            if arr[i][j] != 1:
                dp[i][j] = solve(i+1, j) + solve(i, j+1)
            else:
                return 0
            return dp[i][j]

        return solve(0, 0)