class Solution {
public:
    static bool HelperSort(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; 
    } 

    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end(), HelperSort);
        int i = 0;
        // while(i<n) {
        //     if(i+1 < n && nums[i][1] >= nums[i+1][0]) {
        //         res.push_back({nums[i][0], max(nums[i][1], nums[i+1][1])});i+=1;
        //     }
        //     else {
        //         res.push_back({nums[i][0], nums[i][1]});i+=1;
        //     }
        // }

        for(int i=0; i<n; i++) {
            if(ans.empty() || ans.back()[1] < nums[i][0]) {
                ans.push_back(nums[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }
        return ans;
    }
};