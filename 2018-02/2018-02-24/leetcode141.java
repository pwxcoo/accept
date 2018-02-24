/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    两个指针
 */

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode fast = head.next, slow = head;
        
        while(fast != null && fast.next != null)
        {
            if(slow == fast) 
                return true;
            
            fast = fast.next.next;
            slow = slow.next;
        }
        
        return false;
    }
}