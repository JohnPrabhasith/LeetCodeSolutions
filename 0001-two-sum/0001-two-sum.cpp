#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;   
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int ans = target - nums[i];

            if(mp.count(ans)) {
                return {mp[ans], i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};