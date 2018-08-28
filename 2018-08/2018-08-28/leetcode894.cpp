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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N == 0) return res;
        if (N == 1) 
        {
            res.push_back(new TreeNode(0));
            return res;
        }
        
        
        for (int i = 1; i < N; )
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - i - 1);
            
            for (auto l: left)
            {
                for (auto r: right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
            }
            
            i += 2;
        }
        return res;
    }
};