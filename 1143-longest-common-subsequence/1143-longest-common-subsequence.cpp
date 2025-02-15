class Solution {
private:
    int dfs(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) return dp[i][j] = 1 + dfs(i-1, j-1, s1, s2, dp);

        return dp[i][j] = max(dfs(i-1, j, s1, s2, dp), dfs(i, j-1, s1, s2, dp));

    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         dp[i][j] = -1;
        //     }
        // }
        
        // return dfs(m-1, n-1, s1, s2, dp);

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};