class Solution {
private:
    int dfs(int n, vector<int>& arr, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        else if(dp[n] != -1) return dp[n];
        int pick = arr[n-1] + dfs(n-2, arr,dp);
        int notPick = dfs(n-1, arr,dp);
        return dp[n] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++) {
            dp[i] = max((dp[i-2]+nums[i-1]), dp[i-1]);
        }
        return dp[n];
        // return dfs(n, nums,dp);
    }
};