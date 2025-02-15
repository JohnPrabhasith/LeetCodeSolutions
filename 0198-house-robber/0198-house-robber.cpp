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
        vector<int> dp(n+1,-1);

        return dfs(n, nums,dp);
    }
};