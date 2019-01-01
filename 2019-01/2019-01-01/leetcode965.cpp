/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int l = root->left ? root->left->val : root->val;
        int r = root->right ? root->right->val : root->val;
        return isUnivalTree(root->left) && isUnivalTree(root->right) && root->val == l && root->val == r;
    }
};