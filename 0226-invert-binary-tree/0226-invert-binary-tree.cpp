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
private:
    TreeNode* dfs(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};