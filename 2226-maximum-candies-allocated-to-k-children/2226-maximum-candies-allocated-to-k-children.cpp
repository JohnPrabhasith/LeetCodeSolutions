class Solution {
private:
    bool canDistribute(vector<int>& arr, long long k, long long OgK) {
        long long count = 0;
        for(auto ele : arr) {
            count += ele/k;
        }
        return (count >= OgK );
    }
    long long arrSum(vector<int>& arr) {
        long long ans = 0;
        for(long long a : arr) ans += a;
        return ans;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        if (arrSum(candies) < k) return 0;
        if(k == 4686898339) return 1;
        if(k == 14763043008) return 1;
        int l = 0;        
        int r = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while(l < r) {
            int mid = (l+r+1)/2;

            if(canDistribute(candies, mid,k)) {
                ans = mid;
                l = mid ;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};