/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    用队列来层次遍历
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        
        if(root != null) q.offer(root);
        while(!q.isEmpty())
        {
            int size = q.size();
            List<Integer> temp = new ArrayList<>();
            while(size-- != 0)
            {
                TreeNode t = q.poll();
                if(t.left != null) q.offer(t.left);
                if(t.right != null) q.offer(t.right);
                temp.add(t.val);
            }
            res.add(temp);
        }
        return res;
    }
}