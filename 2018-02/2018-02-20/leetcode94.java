/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    中序遍历
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        
        Stack<TreeNode> st = new Stack<>();
        if(root != null) st.push(root);
        while(!st.empty())
        {
            TreeNode now = st.pop();
            if(now.left == null)
            {
                inorder.add(now.val);
                if(now.right != null) st.push(now.right);
            }
            else
            {
                TreeNode temp = now.left;
                now.left = null;
                st.push(now);
                st.push(temp);
            }
        }
        
        return inorder;
    }
}