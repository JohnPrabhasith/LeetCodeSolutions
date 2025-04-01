class Solution {
long long dp[100000];
private:    
    long long dfs(vector<vector<int>>& nums, int idx, int n) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        // for(int i=0; i<n; i++) {
        //     cout << idx << "," << count << "\n";
        // }
        
        long long countbyTaking = dfs(nums, idx + 1 + nums[idx][1], n) + nums[idx][0];
        long long countbyNotTaking = dfs(nums, idx + 1, n); 

        return dp[idx] = max(countbyTaking, countbyNotTaking);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp, -1, n*sizeof(long long));
        return dfs(questions, 0, n); // 0 -> idx
    }
};