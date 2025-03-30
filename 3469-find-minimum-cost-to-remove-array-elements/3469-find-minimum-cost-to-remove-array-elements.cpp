class Solution {
int n;
public:
    int minCost(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(arr, dp, 0, 1); // 0 -> prevIndex, 1 -> currIndex
    }

private:
    int solve(vector<int>& arr, vector<vector<int>>& dp, int prevIndex, int currIndex) {
        
        //Base Case :
        if (currIndex == n) return arr[prevIndex];
        if (currIndex == n-1) return max(arr[currIndex], arr[prevIndex]);
        if(dp[currIndex][prevIndex] != -1) return dp[currIndex][prevIndex];
        
        // dp :
        int op1 = max(arr[prevIndex], arr[currIndex]) + solve(arr, dp, currIndex + 1, currIndex + 2);
        int op2 = max(arr[currIndex], arr[currIndex+1]) + solve(arr, dp, prevIndex, currIndex + 2);
        int op3 = max(arr[prevIndex], arr[currIndex+1]) + solve(arr, dp, currIndex, currIndex + 2);

        // return Statement :
        return dp[currIndex][prevIndex] = min({op1, op2, op3});
    }

};