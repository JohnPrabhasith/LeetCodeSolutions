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
    bool dfs(TreeNode* tree, int targetSum) {
        if(!tree) return false;
        if(tree->left == nullptr && tree->right == nullptr) return targetSum == tree->val;
        return dfs(tree->left, targetSum-tree->val) || dfs(tree->right, targetSum-tree->val); 
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, targetSum);
    }
};