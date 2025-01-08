class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        int mini = arr[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<arr[high]){
                mini = min(arr[low],mini);
                break;
            }
            mini = min(arr[mid],mini);
            if(arr[mid]>=arr[low]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return mini;
    }
};