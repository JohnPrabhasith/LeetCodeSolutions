class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string maxPal = "";

        for(int i=0; i<s.size(); i++) {
            int len = 0;
            //even numbers
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(r-l+1 > maxLen) {
                    maxPal = s.substr(l, r-l+1);
                    maxLen = r-l+1;
                }
                l--;r++;
            }
            //odd
            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if(r-l+1 > maxLen) {
                    maxPal = s.substr(l, r-l+1);
                    maxLen = r-l+1;
                }
                l--;r++;
            }
        }
        return maxPal;
    }
};