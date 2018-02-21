/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    先序遍历和中序遍历构造树
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
    TreeNode construct(int[] preorder, int[] inorder, int pleft, int iright, int len)
    {
        if(len <= 0) return null;
        else if(len == 1) return new TreeNode(preorder[pleft]);
        
        int cut = iright;
        for(int i = iright; i < iright + len; i++)
        {
            if(preorder[pleft] == inorder[i]) 
            {
                cut = i;
                break;
            }
        }
        
        TreeNode r = new TreeNode(preorder[pleft]);
        r.left = construct(preorder, inorder, pleft + 1, iright, cut - iright);
        r.right = construct(preorder, inorder, pleft + 1 + cut - iright, cut + 1, len - cut + iright - 1);
        return r;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return construct(preorder, inorder, 0, 0, preorder.length);
    }
}