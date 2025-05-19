class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();

        vector<int> maxPrefixLeft(n,INT_MAX);
        vector<int> maxPrefixRight(n,INT_MAX);
        int minValue = 0;
        maxPrefixLeft[0] = arr[0];
        maxPrefixRight[n-1] = arr[n-1];

        for(int i=1; i<n; i++) {
            minValue = max(maxPrefixLeft[i-1], arr[i]);
            maxPrefixLeft[i] = minValue;
        }

        for(int i=n-2; i>=0; i--) {
            minValue = max(maxPrefixRight[i+1], arr[i]);
            maxPrefixRight[i] = (minValue);
        }

        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += min(maxPrefixLeft[i], maxPrefixRight[i]) - arr[i];
        }
        return ans;
    }
};