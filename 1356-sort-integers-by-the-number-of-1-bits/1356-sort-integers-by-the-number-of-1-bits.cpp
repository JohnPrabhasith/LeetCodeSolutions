class Solution {
private:
    static int count_bits(int a) {
        int count = 0;
        while(a > 0) {
            count++;
            a = a & (a-1);
        }
        return count;
    }

    static bool compare(int a, int b) {
        int aBits = count_bits(a);
        int bBits = count_bits(b);

        if(aBits == bBits) {
            return a < b;
        }

        return aBits < bBits;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};