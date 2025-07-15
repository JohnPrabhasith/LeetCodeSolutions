class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        # n = len(arr)
        # memo = {}

        # def solve(row, col):
        #     if col >= n or col < 0:
        #         return 10e9+7
        #     if row == 0:
        #         return arr[row][col]
        #     if (row, col) in memo:
        #         return memo[(row, col)]
        #     res = 10e9 + 7
        #     for prev_col in range(n):
        #         if col != prev_col:
        #             res = min(res, arr[row][col] + solve(row-1, prev_col))
        #     memo[(row, col)] = res
        #     return res

        # res = 10e9 +7
        # for i in range(n):
        #     res = min(res, solve(n-1, i))
        # return res

        n = len(arr)
        dp = arr[0]
        for row in range(1, n):
            res = [10e9 + 7]*n
            for col in range(n):
                for next_col in range(n):
                    if col != next_col:
                        res[col] = min(res[col], arr[row][col] + dp[next_col])
            dp = res
        return min(dp)


        