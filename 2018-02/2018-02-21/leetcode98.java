/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    二叉搜索树，中序遍历
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        TreeNode pre = null, now = root;
        while(now != null || !st.empty())
        {
            while(now != null)
            {
                st.push(now);
                now = now.left;
            }
            if(!st.empty())
            {
                now = st.pop();
                if(pre != null && pre.val >= now.val) return false;
                pre = now;
                now = now.right;
            }
        }
        return true;
    }
}