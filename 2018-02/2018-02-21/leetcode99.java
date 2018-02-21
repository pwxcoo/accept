/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    二叉搜索树，中序遍历，一次错误可以直接交换，两次错误说明两者较远。
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
    public void recoverTree(TreeNode root) {
        TreeNode mistake1 = null, mistake2 = null;
        Stack<TreeNode> st = new Stack<>();
        TreeNode now = root, pre = null;
        while(now != null || !st.empty())
        {
            while(now != null)
            {
                st.push(now);
                now = now.left;
            }
            if(!st.empty())
            {
                now = st.pop();
                if(pre != null && now.val <= pre.val)
                {
                    if(mistake1 == null)
                    {
                        mistake1 = pre; 
                        mistake2 = now;
                    }
                    else mistake2 = now;
                }
                pre = now;
                now = now.right;
            }
        }
        
        if(mistake1 != null)
        {
            int temp = mistake1.val;
            mistake1.val = mistake2.val;
            mistake2.val = temp;
        }
    }
}