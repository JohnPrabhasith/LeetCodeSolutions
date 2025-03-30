class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            mp[s[i]] = i;
        }

        int size = 0;
        int end = 0;
        vector<int> res;
        int i =0;

        while(i < n) {
            end = max(mp[s[i]], end);
            if(i == end) {
                res.push_back(end - size + 1);
                size = i+1;
            }
            i++;
        }
        return res;
    }
};