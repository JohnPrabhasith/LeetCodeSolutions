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
            ## Approach 2
            '''
            if else:
                dp[i][j] = arr[i][j] +  min((i+1), (j-1, j, j+1))
                arr[i][j] += min(arr[i+1][j], .....)
               ''' 
            dp = temp
        return min(dp)





        ##Approach 3 : Recursive
        # dp = [[-1]*(n+1) for _ in range(m+1)]
        # def solve(i, j):
        #     if j < 0 or j >= m: return 1e9
        #     if i == 0: return arr[0][j]
        #     if dp[i][j] != -1: return dp[i][j]
        #     s = arr[i][j] + solve(i-1, j)        ## Straight up
        #     dl = arr[i][j] + solve(i-1, j-1)     ## Diagonal left
        #     dr =  arr[i][j] + solve(i-1, j+1)    ## Diagonal Right
        #     dp[i][j] = min(s, dl, dr)
        #     return dp[i][j]

        # return min(solve(m-1,j) for j in range(n))

