class Solution {
private:
    int findMax(vector<int> &arr) {
        int maxElement = INT_MIN;
        int n = arr.size();

        for(int i=0; i<n; i++) {
            maxElement = max(maxElement, arr[i]);
        }
        
        return maxElement;
    }

    int CountHours(vector<int> &arr, int h) {
        int n = arr.size();
        int totalHours = 0;
        for(int i=0; i<n; i++) {
            totalHours += ceil((double)(arr[i])/(double)(h));
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = findMax(piles);        
        int l = 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int reqTime = CountHours(piles, mid);
            if(reqTime <= h) {
                r = mid - 1;
            }
            else {
                l = mid +1;
            }
        }
        return l;
    }
};