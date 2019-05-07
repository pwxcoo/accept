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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        stack<TreeNode*> st;
        auto now = root;
        while(now || !st.empty()) {
            while(now) {
                st.push(now);
                now = now->right;
            }

            if (!st.empty()) {
                auto t = st.top(); st.pop();
                sum += t->val;
                t->val = sum;

                now = t->left;
            }
        }

        return root;
    }
};