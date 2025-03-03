class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for (auto num : mp) {
            pq.push({num.second, num.first});
        }

        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};