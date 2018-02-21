/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    后序遍历和中序遍历构造树
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
    TreeNode construct(int[] inorder, int[] postorder, int ileft, int pleft, int len)
    {
        if(len <= 0) return null;
        if(len == 0) return new TreeNode(postorder[pleft]);
        
        int cut = ileft;
        for(int i = ileft; i < ileft + len; i++)
            if(postorder[pleft + len - 1] == inorder[i])
            {
                cut = i;
                break;
            }
        
        TreeNode r = new TreeNode(inorder[cut]);
        r.left = construct(inorder, postorder, ileft, pleft, cut - ileft);
        r.right = construct(inorder, postorder, ileft + cut - ileft + 1, pleft + cut - ileft, len - cut + ileft - 1);
        return r;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return construct(inorder, postorder, 0, 0, inorder.length);
    }
}