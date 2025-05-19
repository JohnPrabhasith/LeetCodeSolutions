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
        int a = 0;
        int b = nums[0];

        for(int i=1; i<n; i++) {
            int val = a;
            a = b;
            b = max(val + nums[i], a);
        }
        return b;
    }
};