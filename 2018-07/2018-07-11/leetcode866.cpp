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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        postOrder(root, 0);
        return p;
    }
private:
    int maxDepth = 0;
    TreeNode* p = nullptr;
    int postOrder(TreeNode* root, int depth) {        
        maxDepth = max(maxDepth, depth);
        int left = (root->left == nullptr) ? depth : postOrder(root->left, depth+1);
        int right = (root->right == nullptr) ? depth : postOrder(root->right, depth+1);

        if(left == maxDepth && right == maxDepth) p = root;
        return max(left, right);
    }
};