class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int sol = 0;
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(int i=1; i<n; i++) {
            if(prefix[i] >= prefix[n]-prefix[i]) {
                sol += 1;
            }
        }
        return sol;
    }
};