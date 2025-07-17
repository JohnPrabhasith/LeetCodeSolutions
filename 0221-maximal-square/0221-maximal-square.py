class Solution:
    def maximalSquare(self, arr: List[List[str]]) -> int:
        rows, cols = len(arr), len(arr[0])
        dp = {}

        def solve(r, c):
            if r >= rows or c >= cols:
                return 0
            elif (r,c) in dp:
                return dp[(r,c)]
            down = solve(r+1, c)
            right = solve(r, c+1)
            diag = solve(r+1, c+1)
            dp[(r,c)] = 0
            if arr[r][c] == '1':
                dp[(r,c)] = 1 + min(down, diag, right)
            return dp[(r,c)]
        solve(0,0)
        return max(dp.values()) ** 2

                