class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> powersOfTwo;
        for (int i = 0; (1 << i) <= 1e9; ++i) {
            powersOfTwo.push_back(to_string(1 << i));
        }

        string nStr = to_string(n);
        vector<int> nDigitCount(10, 0);
        for (char digit : nStr) {
            nDigitCount[digit - '0']++;
        }

        for (auto power : powersOfTwo) {
            vector<int> powerDigitCount(10, 0);
            for (char digit : power) {
                powerDigitCount[digit - '0']++;
            }

            if (nDigitCount == powerDigitCount) {
                return true;
            }
        }

        return false;
    }
};