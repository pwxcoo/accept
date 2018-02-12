/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    合并链表
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode res = head;
        
        while(l1 != null && l2 != null)
        {
            if(l1.val < l2.val)
            {
                head.next = l1;
                l1 = l1.next;
            }
            else
            {
                head.next = l2;
                l2 = l2.next;
            }
            
            head = head.next;
        }
        
        if(l1 == null) head.next = l2;
        else head.next = l1;
        return res.next;
    }
}