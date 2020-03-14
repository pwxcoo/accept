## Intuition

在二叉树找出最长的 zigzag 路径。

----

递归 dfs。需要返回三个信息 `[left, right, result]`。

1. `left` 表示当前 root 下一步 traverse left 的最长 zigzag 长度。
2. `right` 表示当前 root 下一步 traverse right 的最长 zigzag 长度。
3. `result` 表示当前子树最大的 zigzag 长度。


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
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return {-1, -1, -1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int res = max(max(left[2], right[2]), 1 + max(left[1], right[0]));
        return {left[1] + 1, right[0] + 1, res};
    }
};
```

时间复杂度：$$O(n)$$