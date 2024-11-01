class Solution {
public:
    string makeFancyString(string s) {
        int count = 1;
        string ans = "";
        if(s.length() < 3) {
            return s;
        }
        for(int i=0; i<s.length()-2; i++){
            if(s[i] == s[i+1] && s[i] == s[i+2]) {
                ans += "";
            }
            else{
                ans += s[i];
            }
        }
        for(int i=s.length()-2; i<s.length(); i++) {
            ans += s[i];
        }
        return ans;
    }
};