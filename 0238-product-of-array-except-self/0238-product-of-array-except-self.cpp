class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1;
        int post = 1;
        int n = nums.size();
        vector<int> arr(n);

        for(int i=0; i<n; i++) {
            arr[i] = pre;
            pre *= nums[i];
        }

        for(int i=n-1; i>=0; i--) {
            arr[i] *= post;
            post *= nums[i];
        }
        return arr;
    }
};