class Solution:
    def minimumTotal(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        # if m == 0:
        #     return 0
        # if m == 1:
        #     return arr[0][0]

        # dp = arr[-1][:]

        for i in range(m-2, -1, -1):
            for j in range(i+1):
                # dp[j] = arr[i][j] + min(dp[j], dp[j+1])
                arr[i][j] += min(arr[i+1][j], arr[i+1][j+1])
        return arr[0][0]