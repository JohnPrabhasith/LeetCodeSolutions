class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if(v.size() == 1) {
            return v[0];
        }
        
        sort(v.begin(), v.end());
        int n = v.size();
        int min_length = v[0].size();
        string str = "";
        // string first = v[0];
        // string last = v[n-1];
        for(int i=0; i<v[0].size(); i++) {
            if(v[0][i] != v[n-1][i]) {
                return str;
            }
            str += v[0][i];
            // cout << v[0][i] << "," << v[n-1][i] << "\n";
        } 

        return str;
    }
};