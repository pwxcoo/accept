/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    求树的路径和
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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        if(root.right == null && root.left == null) return root.val == sum;
        return hasPathSum(root.right, sum - root.val) || hasPathSum(root.left, sum - root.val);
    }
}