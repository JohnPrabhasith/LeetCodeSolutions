class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp((nums.size()) + 1);
        return rob(nums, dp, nums.size());
    }
private:
    int rob(vector<int>& nums, vector<int>& dp, int n) {
        // if(n < 0) return 0;
        // if(dp[n] != -1) return dp[n];
        // return dp[n] = max(rob(nums, dp, n-2) + nums[n], rob(nums, dp, n-1));
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=1; i<n; i++) {
            int val = nums[i];
            dp[i+1] = max(dp[i], dp[i-1] + val);
        }
        return dp[n];
    }
};