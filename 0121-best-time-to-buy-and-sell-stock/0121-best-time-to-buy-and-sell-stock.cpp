class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minVal = arr[0];
        int maxProfit = 0;

        for(int i=0; i<arr.size(); i++) {
            if(minVal > arr[i]) {
                minVal = arr[i];
            }

            if(arr[i] - minVal > maxProfit) {
                maxProfit = arr[i] - minVal;
            }
        }
        return maxProfit;
    }
};