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
    void dfs(TreeNode* root, vector<string>* num, string str) {
        if(root->left == nullptr && root->right == nullptr) {
            num->push_back(str);
            return;
        }
        if(root->left != nullptr) {
            dfs(root->left, num, str+to_string(root->left->val));
        }
        if(root->right != nullptr) {
            dfs(root->right, num, str+to_string(root->right->val));
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> numbers;
        string s = to_string(root->val);
        int sum = 0;
        dfs(root, &numbers, s);
        for(int i=0; i<numbers.size(); i++) {
            sum += stoi(numbers[i]);
        }
        return sum;
    }
};