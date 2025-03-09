class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int l = 0;
        int n = arr.size();
        int limit = n + k - 1;
        int count = 0;

        while(l < n) {
            int r = l + 1;
            while(r < limit and arr[(r-1) % n] != arr[r % n]) {
                r++;
            }
            if(r-l >= k) {
                count += r-l - k+1;
            }
            l = r;
        }
        return count;
    }
};