class Solution {

private:
    void dfs(vector<vector<int>>& arr, vector<int>& temp, int k, int digit, int target) {
        if (temp.size() == k) {
            if (target == 0) {
                arr.push_back(temp);
            }
            return;
        }
        for(int i=digit; i<=9; i++) {
            if(i > target) {
                break;
            }
            temp.push_back(i);
            dfs(arr, temp, k, i+1, target - i);
            temp.pop_back();
        }
        // dfs(arr, temp, k, i, target);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> arr;
        vector<int> temp;

        dfs(arr, temp, k, 1, n);
        return arr;
    }
};