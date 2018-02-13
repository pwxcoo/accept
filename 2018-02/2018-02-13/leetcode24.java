/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    两两交换链表两个结点
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
    public ListNode swapPairs(ListNode head) {
        ListNode pos = new ListNode(0);
        pos.next = head;
        ListNode res = pos;
        
        while(pos != null && pos.next != null && pos.next.next != null)
        {
            ListNode three = pos.next.next.next;
            pos.next.next.next = pos.next;
            ListNode two = pos.next.next;
            pos.next.next = three;
            pos.next = two;
            pos = pos.next.next;
        }
        
        return res.next;
    }
}