/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()) {
            int qLen = q.size();
            TreeNode* rightElement = nullptr;

            for(int i=0; i<qLen; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node) {
                    rightElement = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(rightElement){
                ans.push_back(rightElement->val);
            }
        }
        return ans;
    }
};