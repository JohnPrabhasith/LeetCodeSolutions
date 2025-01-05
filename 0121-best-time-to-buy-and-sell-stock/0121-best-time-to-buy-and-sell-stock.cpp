class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minVal = arr[0];
        int maxProfit = 0;

        for(int i=0; i<arr.size(); i++) {

            minVal = min(minVal, arr[i]);
            maxProfit = max(maxProfit, arr[i]-minVal);
            
        }
        return maxProfit;
    }
};