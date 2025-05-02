class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> v(n);
        vector<int>d(n,0);

        for (auto& x:prerequisites) {
            v[x[1]].push_back(x[0]);
            d[x[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++) {
            if(d[i]==0)
                q.push(i);
        }

        vector<int> result;
        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for (int x:v[curr]) {
                d[x]--;
                if (d[x] == 0)
                    q.push(x);
            }
        }
        if (result.size()!=n)
            return {};
        
        return result;
    }
};