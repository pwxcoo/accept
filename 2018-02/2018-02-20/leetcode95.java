/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    生成搜索树.dfs
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
    List<TreeNode> generate(int left, int right)
    {
        List<TreeNode> tree = new ArrayList<>();
        if(left > right) 
        {
            tree.add(null);
            return tree;
        }
        else if(left == right) 
        {
            tree.add(new TreeNode(left));
            return tree;
        }
        
        for(int i = left; i <= right; i++)
        {         
            List<TreeNode> leftTree = generate(left, i - 1);
            List<TreeNode> rightTree = generate(i + 1, right);
            for(TreeNode l : leftTree)
                for(TreeNode r : rightTree)
                {
                    TreeNode temp = new TreeNode(i);
                    temp.left = l;  temp.right = r;
                    tree.add(temp);
                }
        }
        return tree;
    }
    
    public List<TreeNode> generateTrees(int n) {
        if(n <= 0) return new ArrayList<TreeNode>();
        return generate(1, n);
    }
}