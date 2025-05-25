class Solution {
public:
    vector<int> findWordsContaining(vector<string>& arr, char x) {
        vector<int> ans;
        int n = arr.size();

        for(int i=0; i<n; i++) {
            string word = arr[i];
            int m = word.size();
            for(int j=0; j<m; j++) {
                if (word[j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};