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
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0,0};

        pair<int, int> leftPair = dfs(root->left);
        pair<int, int> rightPair = dfs(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.second, leftPair.first) + max(rightPair.second, rightPair.first);

        return {withRoot, withoutRoot};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.second, ans.first);
    }
};