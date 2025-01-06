class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi_ = INT_MIN;
        int curSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            curSum += nums[i];
            maxi_ = max(curSum, maxi_);

            if(curSum < 0) {
                // neglect
                curSum = 0;
            }
        }
        return maxi_;
    }
};