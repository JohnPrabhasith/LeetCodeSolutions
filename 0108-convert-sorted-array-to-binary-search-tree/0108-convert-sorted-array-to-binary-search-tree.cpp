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
    TreeNode* sortedArrayToBST(vector<int> nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* tree = new TreeNode(nums[mid]);
        tree->val = nums[mid];
        tree->left = sortedArrayToBST(nums, left, mid-1);
        tree->right = sortedArrayToBST(nums, mid+1, right);
        return tree;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBST(nums, 0, n-1);
    }
};