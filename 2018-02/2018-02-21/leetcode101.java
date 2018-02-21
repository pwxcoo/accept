/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    判断是否镜像树
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true; 
        Stack<TreeNode> l = new Stack<>();
        Stack<TreeNode> r = new Stack<>();

        if(root.left != null) l.push(root.left);  
        if(root.right != null) r.push(root.right);
        
        while(!l.empty() && !r.empty())
        {
            TreeNode le = l.pop(), ri = r.pop();
            if(le.val != ri.val) return false;
            
            if(le.left != null && ri.right != null) 
            {
                l.push(le.left);
                r.push(ri.right);
            }
            else if(le.left == null && ri.right != null || le.left != null && ri.right == null) return false;

            if(le.right != null && ri.left != null) 
            {
                l.push(le.right);
                r.push(ri.left);
            }
            else if(le.right == null && ri.left != null || le.right != null && ri.left == null) return false;
        }
        
        return l.empty() && r.empty();
    }
}