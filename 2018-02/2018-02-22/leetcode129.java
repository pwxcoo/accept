/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    dfs
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
    int res = 0;
    void dfs(int now, TreeNode root)
    {
        if(root == null) return;
        now = now * 10 + root.val;
        if(root.left == null && root.right == null) 
        {
            res += now;
            return;
        }
        
        if(root.left != null) dfs(now, root.left);
        if(root.right != null) dfs(now, root.right);
    }
    
    public int sumNumbers(TreeNode root) {
        
        dfs(0, root);
        return res;
    }
}