/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    两个栈模拟zigzag
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Stack<TreeNode> st1 = new Stack<>();
        Stack<TreeNode> st2 = new Stack<>();
        if(root != null) st2.push(root);
        
        boolean dir = false;    // left -> right is true
        while(!st1.empty() || !st2.empty())
        {
            Stack<TreeNode> st = st1.empty() ? st2 : st1;
            List<Integer> temp = new ArrayList<>();
            while(!st.empty())
            {
                TreeNode t = st.pop();
                temp.add(t.val);
                if(dir)
                {
                    if(t.right != null) st2.push(t.right);
                    if(t.left != null) st2.push(t.left);
                }
                else
                {
                    if(t.left != null) st1.push(t.left);
                    if(t.right != null) st1.push(t.right);
                }
            }
            res.add(temp);
            dir = !dir;
        }
        return res;
    }
}