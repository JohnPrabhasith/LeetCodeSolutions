class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
           if(i>0 &&  arr[i] == arr[i-1]) continue;
            int a = arr[i];
            int l = i+1, r = n-1;
            while(l<r){
                int ThreeSum = a + arr[l] + arr[r];
                if(ThreeSum > 0){
                    r--;
                }
                else if(ThreeSum < 0){
                    l++;
                }
                else{
                    ans.push_back({a,arr[l],arr[r]});
                    l++;
                    while(arr[l] == arr[l-1] && l<r) l++;
                }
            }
        }       
        return ans;
    }
};