class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = 0;
        map<vector<int>, int> mp; 
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j =0; j<n; j++){
                temp.push_back(arr[i][j]);
            }
            mp[temp]++;
        }
        
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j =0; j<n; j++){
                temp.push_back(arr[j][i]);
            }
            ans += mp[temp];
        }
        // 
    
        return ans;
    }
};