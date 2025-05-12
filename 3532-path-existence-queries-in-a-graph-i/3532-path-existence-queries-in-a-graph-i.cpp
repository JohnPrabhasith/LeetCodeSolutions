class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 1) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                uf.unionSets(i, i + 1);
            }
        }

        vector<bool> answer;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(uf.find(u) == uf.find(v));
        }

        return answer;
    }
};