class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n+1, 0), suf(n+1, 0);
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + (customers[i] == 'N');
        }
        for(int i=n-1; i>=0; i--){
            suf[i] = suf[i+1] + (customers[i] == 'Y');
        }
            // yyny pre = 0 0 0 1 1
            //     suff = 3 2 1 1 0
        int ans = -1;
        int min_penalty = 1e6;
        for(int i=0; i<=n; i++){
            int penalty = pre[i] + suf[i];
            if(min_penalty > penalty){
                ans = i;
                min_penalty = penalty;
            }
        }
        return ans;
    }
};