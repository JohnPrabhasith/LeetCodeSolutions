class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int, int>>> vec(n);
        for (auto&x : roads){
            int u=x[0], v=x[1], t=x[2];
            vec[u].emplace_back(v, t);
            vec[v].emplace_back(u, t);
        }

        vector<long long> d(n, LLONG_MAX);
        vector<int> w(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        d[0] = 0;
        w[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > d[node]) 
                continue;
            for (auto& [next, t]:vec[node]) {
                long long newTime=time + t;
                if (newTime<d[next]) {
                    d[next]=newTime;
                    w[next]=w[node];
                    pq.push({newTime, next});
                } 
                else if (newTime == d[next]) {
                    w[next] = (w[next]+w[node]) % MOD;
                }
            }
        }

        return w[n-1];
    }
};