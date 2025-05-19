class Solution {
vector<int> temp;
private:
    void solve(vector<int>& arr, vector<vector<int>>& ans, int ind, int n) {
        if(ind >= n) {
            ans.push_back(temp);
            return;
        }
        // for(int i=ind; i<n; i++) {
        //     temp.push_back(arr[i]);
        //     solve(arr, ans, ind+1, n);
        // }
        temp.push_back(arr[ind]);
        solve(arr, ans, ind+1, n);

        temp.pop_back();
        solve(arr, ans, ind+1, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0, nums.size());
        return ans;
    }
};