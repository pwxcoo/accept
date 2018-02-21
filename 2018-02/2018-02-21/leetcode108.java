/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    构造高度平衡二叉树
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
    TreeNode construct(int[] nums, int left, int right)
    {
        if(left > right) return null;
        else if(left == right) return new TreeNode(nums[left]);
        
        int mid = (left + right) / 2;
        TreeNode r = new TreeNode(nums[mid]);
        r.left = construct(nums, left, mid - 1);
        r.right = construct(nums, mid + 1, right);
        return r;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return construct(nums, 0, nums.length - 1);
    }
}