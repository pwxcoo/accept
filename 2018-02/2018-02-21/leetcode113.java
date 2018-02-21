/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    求树的路径和的路径
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
    void dfs(List<List<Integer>> res, List<Integer> cur, TreeNode root, int sum)
    {
        if(root == null) return;
        cur.add(root.val);
        if(root.right == null && root.left == null)
        {
            if(root.val == sum)
            {
                res.add(new ArrayList<Integer>(cur));
            }
            cur.remove(cur.size() - 1);
            return;
        }
        
        dfs(res, cur, root.left, sum - root.val);
        dfs(res, cur, root.right, sum - root.val);
        cur.remove(cur.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList<Integer>(), root, sum);
        return res;
    }
}