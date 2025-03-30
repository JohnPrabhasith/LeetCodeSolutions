class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int size = 0;
        int end = 0;
        for(int i=0; i<n; i++) {
            end = max(end, mp[s[i]]);
            size++;
            if(i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};