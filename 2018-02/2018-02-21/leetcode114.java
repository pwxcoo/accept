/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    前序遍历
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
    public void flatten(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        if(root != null) st.push(root);
        TreeNode pre = new TreeNode(0);
        
        while(!st.empty())
        {
            TreeNode t = st.pop();
            if(t.right != null) st.push(t.right);
            if(t.left != null) st.push(t.left);
            
            pre.right = t;
            pre = t;
            pre.left = null;
        }
        pre.right = null;
    }
}