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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bool end = false;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            if (!t) end = true;
            else {
                if (end) return false;
                
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};