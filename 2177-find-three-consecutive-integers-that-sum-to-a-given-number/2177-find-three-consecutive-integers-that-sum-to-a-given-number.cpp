class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long ans = num/3;
        if(((ans) + (ans + 1) + (ans - 1)) == num) 
            return {(ans - 1), (ans) , (ans + 1) };
        else 
            return {};
    }
};