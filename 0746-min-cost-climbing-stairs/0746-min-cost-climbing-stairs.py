class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [-1] * (n + 1)            

        # def minCost(n):
        #     if n < 0: return 0
        #     if n == 0 or n == 1: return cost[n]
        #     if dp[n] != -1: return dp[n]
            
        #     dp[n] = cost[n] + min(minCost(n-1), minCost(n-2))
        #     return dp[n]
        
        # return min(minCost(n-1), minCost(n-2))
        dp[0], dp[1] = cost[0], cost[1]
        for i in range(2, n):
            dp[i] = cost[i] + min(dp[i-1], dp[i-2])
        return min(dp[n-1], dp[n-2])
