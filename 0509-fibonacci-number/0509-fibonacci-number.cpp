class Solution {
public:
    int fib(int n){
        vector<int> dp(n+1, -1);
        // return solve(n, dp);
        
        //Tabulation
        if((n ==0) or (n == 1)) return n;
        dp[0] = 0;  //a
        dp[1] = 1;  //b
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
        
    }
    // int solve(int n, vector<int>&dp) {
    //     // base case
    //     if ((n == 0) or (n == 1)) return n;
    //     //Logic
    //     // return fib(n-1) + fib(n-2);
        
    //     if (dp[n] != -1){
    //         return dp[n];
    //     }
        
    //     dp[n] = solve(n-1, dp) + solve(n-2, dp);
    //     return dp[n];
    //     // 5 
    //     // /\
    //     // 4 3
    //     // /\
    //     // 3 2  2 1
    //     // 2 1 1 0 1 0 
    //     // 1 0
        
    //     // O(2^n)
        // [-1, -1, 1, -1, -1, -1]
        
    
};