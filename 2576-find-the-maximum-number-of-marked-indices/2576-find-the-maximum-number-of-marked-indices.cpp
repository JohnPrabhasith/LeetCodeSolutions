class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        // vector<pair<int, int>> temp;
        // for(int i=0; i<n; i++) {
        //     temp.push_back({i, nums[i]});
        // }
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = (n/2);
        int i = 0;
        int j = mid;
        int ans = 0;
        while(i < mid && j < n) {
            if(2*nums[i] <= nums[j]) {
                ans += 2; i++; j++; 
            }
            else {
                j++;
            }
        }
        return ans;
    }
};