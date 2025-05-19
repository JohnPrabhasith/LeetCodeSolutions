class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) 
            return nums[0];
            
        int first = 0;
        int last = n-1;
        //We either leave the first house or the last house.
        int leftToRight = rob(nums, first, last-1);
        int rightToLeft = rob(nums, first+1, last);
        return max(leftToRight, rightToLeft);
        // return 0;
    }
private:
    int rob(vector<int>& nums, int idx, int n) {
        // if(n < i) {
        //     return 0;
        // }
        // return max(rob(nums, i, n-2) + nums[n], rob(nums, i, n-1));

        int first = 0;
        int second = 0;

        for(int i=idx; i<=n; i++) {
            int val = max((first + nums[i]), second);
            first = second;
            second = val;
        }
        return second;
    }
};