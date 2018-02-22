/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    层次遍历
 */

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        Queue<TreeLinkNode> q = new LinkedList<>();
        if(root != null) q.offer(root);
        
        while(!q.isEmpty())
        {
            int size = q.size();
            TreeLinkNode next = null;
            while(size-- > 0)
            {
                TreeLinkNode t = q.poll();
                t.next = next;
                next = t;
                
                if(t.right != null) q.offer(t.right);
                if(t.left != null) q.offer(t.left);
            }
        }
    }
}