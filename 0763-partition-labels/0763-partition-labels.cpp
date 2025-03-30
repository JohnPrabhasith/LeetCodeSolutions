class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int start = 0;
        int end = 0;
        for(int i=0; i<n; i++) {
            end = max(end, mp[s[i]]);
            if(i == end) {
                res.push_back(end - start + 1);
            }
        }
        return res;
    }
};