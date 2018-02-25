/**
 * date: 2018-02-25
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    先序遍历，非递归
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
    public List<Integer> preorderTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        if(root != null) st.push(root);
        List<Integer> res = new ArrayList<>();
        
        while(!st.empty())
        {
            TreeNode t = st.pop();
            res.add(t.val);
            if(t.right != null) st.push(t.right);
            if(t.left != null) st.push(t.left);
        }
        
        return res;
    }
}