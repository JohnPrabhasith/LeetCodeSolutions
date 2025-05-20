class Solution {
private:
    int solve(vector<int>& arr, int bound) {
        int count = 0;
        int ans = 0;
        for(auto x: arr) {
            if(x <= bound) {
                count += 1;
            }
            else{
                count = 0;
            }
            ans += count;
        }
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        // int l = 0;
        // int r = 0;
        // int ans = 0;
        // int n = arr.size();
        // int count = 0;

        // for(auto x: arr) {
        //     if(x < right) {
        //         ans++;

        //     }
        // }

        // while(r < n) {
        //     if(arr[r] >= left && arr[r] <= right) {
        //         ans += (r-l+1);
        //         cout << "\n" << r << " " << l <<"\n";
        //         count = 0;
        //       }
        //     else if(arr[r] < left && ans > 0) {
        //         ans += (r-l-count);
        //         count ++;
        //     }
        //     else if(arr[r] > right){
        //         l = r+1;
        //     }
        //     r++;
        // }
        // return (ans > 0) ? ans : 0;

        return solve(arr, right) - solve(arr, left-1);
    }
};