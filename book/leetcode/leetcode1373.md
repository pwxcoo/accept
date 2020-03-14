## Intuition

在二叉树找出 BST，要求 BST 节点和最大。

----

递归 dfs。需要返回三个信息 `[treeInfo, sum, minimal, maximal]`。

1. `treeInfo`，树的信息，因为 BST 子结构还是 BST 的性质，所以递归需要关系子树是否 BST
    - `0` = empty
    - `1` = not BST
    - `2` = BST
2. `sum` 子树所有节点总和，计算答案需要
3. `minimal` 判断是否仍然是 BST 需要
4. `maximal` 判断是否仍然是 BST 需要


## Solution

```cpp
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
    int res = 0;
    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    /**
     * [isBST(0=empty, 1=notBST, 2=BST), sum, minimal, maximal]
     */
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0, INT_MAX, INT_MIN};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if ((left[0] == 0 || (left[0] == 2 && left[3] < root->val)) &&
            (right[0] == 0 || (right[0] == 2 && right[2] > root->val))) {
            int sum = left[1] + right[1] + root->val;
            int mn = left[0] == 0 ? root->val : left[2];
            int mx = right[0] == 0 ? root->val : right[3];

            res = max(res, sum);

            return {2, sum, mn, mx};
        }

        return {1, 0, INT_MAX, INT_MIN};
    }
};
```

时间复杂度：$$O(n)$$