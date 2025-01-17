class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int count = 0;
        string ans1 = "";
        string ans2 = "";

        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '#'){
                count++;
            }
            else if(count > 0) {
                count--;
            }
            else{
                ans1 += s[i];
            }
        }

        for(int i=t.size()-1; i>=0; i--) {
            if(t[i] == '#'){
                count++;
            }
            else if(count > 0) {
                count--;
            }
            else{
                ans2 += t[i];
            }
        }
        return ans1 == ans2;
    }
};