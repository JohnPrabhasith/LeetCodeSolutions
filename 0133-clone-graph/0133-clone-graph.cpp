/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*, Node*> mp;

private:
    Node* dfs(Node* node) {
        if(node == nullptr) return nullptr;

        if(mp.find(node) != mp.end()) 
            return mp[node];
        
        Node* copy = new Node(node->val);
        mp[node] = copy;

        for(auto neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};