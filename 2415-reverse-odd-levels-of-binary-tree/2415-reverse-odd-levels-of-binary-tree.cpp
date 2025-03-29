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
    void dfs(TreeNode* left, TreeNode* right,int count) {
        if(!left || !right) return;
        if(count % 2 == 0) {
            int tmp =  left->val;
            left->val = right->val;
            right->val = tmp;
        }
        dfs(left->left, right->right, count+1);
        dfs(left->right, right->left ,count+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;
        dfs(root->left, root->right,0);
        return root;
    }
};