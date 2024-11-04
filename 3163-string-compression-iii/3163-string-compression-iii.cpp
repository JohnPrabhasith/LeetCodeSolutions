class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string ans = "";
        int count = 1;
        
        for (int i = 1; i <= word.size(); i++) {
            // Check if current char is different from previous or if we've reached the end
            if (word[i] != word[i - 1]) {
                // Handle counts greater than 9
                while (count >= 10) {
                    ans += "9" + string(1, word[i - 1]);
                    count -= 9;
                }
                // Handle remaining count
                if (count > 0) {
                    ans += to_string(count) + word[i - 1];
                }
                count = 1;
            } else {
                count++;
            }
        }
        
        return ans;
    }
};