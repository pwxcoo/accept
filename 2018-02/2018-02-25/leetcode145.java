/**
 * date: 2018-02-25
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    先序遍历,非递归
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
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        List<Integer> res = new ArrayList<>();
        TreeNode p = root, pre = null;
        
        while(!st.empty() || p != null)
        {
            while(p != null)
            {
                st.push(p);
                p = p.left;
            }
            
            TreeNode t = st.peek();
            if(t.right == null || t.right == pre) 
            {
                pre = t;
                res.add(t.val);
                st.pop(); 
            }
            else p = t.right;
        }
        
        return res;
    }
}