## Intuition

二叉树里找链表。

----

递归。


## Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (head->val != root->val) return false;

        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
```

时间复杂度：$$O(n*min(H,L))$$，`n` 是节点个数，`H` 是二叉树高度，`L` 是链表长度。每个子问题的 `dfs()` 是 $$min(H,L)$$。