class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int> pq;
        int n = arr.size();

        for(int i=0; i<n; i++) {
            pq.push(-arr[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // for(int i=0; i<k; i++) {
        //     pq.push(-arr[i]);
        // }

        // for(int i=k; i<n; i++) {
        //     pq.push(-arr[i]);
        //     if(arr[i] >= pq.top()) {
        //         pq.pop();
        //     }
        // }

        return -pq.top();
    }
};