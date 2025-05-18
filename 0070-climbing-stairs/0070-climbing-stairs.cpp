class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);

        // vector<int> dp(n+1, -1);
        // dp[0] = dp[1] = 1;
        int a, b, c;
        a = b = 1;
        for(int i=2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;

    }
};