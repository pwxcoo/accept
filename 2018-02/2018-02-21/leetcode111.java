/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    求根结点到叶结点最短的路径
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
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.right == null && root.left == null) return 1;
        if(root.right != null)
        {
            int res = minDepth(root.right);
            if(root.left != null)
                res = Math.min(minDepth(root.left), res);
            return res + 1;
        }
        else return minDepth(root.left) + 1;
    }
}