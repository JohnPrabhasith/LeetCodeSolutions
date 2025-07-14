class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        
        dp = arr[-1][:]
        for i in range(m-2, -1, -1):
            temp = [0]*n
            for j in range(n):
                if j == 0:
                    temp[j] = arr[i][j] + min(dp[j], dp[j+1])
                elif j == n-1:
                    temp[j] = arr[i][j] + min(dp[j-1], dp[j])
                else:
                    temp[j] = arr[i][j] + min(dp[j-1], dp[j], dp[j+1])
            dp = temp
        return min(dp)
