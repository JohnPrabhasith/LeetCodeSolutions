class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();
        if (m < n || n == 0) return "";
        map<int, int> window;
        map<int, int> T;

        for(auto x : t) {
            T[x]++;
        }
        int need = T.size();
        int have = 0;

        int l = 0,r = 0;
        int sIndex, eIndex;
        int minCount = INT_MAX;

        while(r < m) {
            int c = s[r];
            window[c]++;
            if(T.count(c) > 0 and window[s[r]] == T[s[r]]) {
                have++;
            }
            while(need == have) {
                if(minCount > (r-l+1)){
                    sIndex = l;
                    eIndex = r;
                    minCount = r-l+1;
                }
                window[s[l]]--;
                if(window.count(s[l]) and (window[s[l]] < T[s[l]])) 
                    have--;
                l++;
            }
            r++;
        }      
        return minCount == INT_MAX ? "" : s.substr(sIndex, minCount);
    }
};