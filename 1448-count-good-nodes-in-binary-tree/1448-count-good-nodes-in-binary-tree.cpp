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
int count = 0;
private:
    void dfs(TreeNode* root, int maxi) {
        if(!root) return;

        if(root->val >= maxi) {
            count += 1;
            maxi = root->val;
        }

        dfs(root->left, maxi);
        dfs(root->right, maxi);

        return;
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};