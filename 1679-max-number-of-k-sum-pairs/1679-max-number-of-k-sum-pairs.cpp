class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        map<int, int> mp;
        int count = 0;
        int n = arr.size();

        for(int i=0; i<n; i++) {
            int res = k - arr[i];

            if(mp.find(res) != mp.end()) {
                count++;
                if(mp[res]-1 == 0){
                    mp.erase(res);
                }
                else{
                    mp[res]--;
                }
            } 
            else{
                if(arr[i] < k) {
                    mp[arr[i]]++;
                }
            }
        }
        return count;
    }
};