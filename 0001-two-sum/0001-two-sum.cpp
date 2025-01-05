#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int ans = target - nums[i];
            if(mp.count(ans)){
                return {mp[ans],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};