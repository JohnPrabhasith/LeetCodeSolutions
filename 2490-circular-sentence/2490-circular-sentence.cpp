class Solution {
public:
    bool isCircularSentence(string s) {

        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word) {
            words.push_back(word);
        }

        int n = words.size();
        for(int i=0; i<n; i++) {
            if(words[i].back() != words[(i+1) % n].front()){
                return 0;
            }
        }
        return 1;
    }
};