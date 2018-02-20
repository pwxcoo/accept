/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    链表操作
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy, pos = head, start;
        
        for(int i = 1; i < m; i++)
        {
            pos = pos.next;
            pre = pre.next;
        }
        start = pre;
        pos = pos.next; pre = pre.next;
        for(int i = 0; i < (n - m); i++)
        {
            ListNode temp = pos.next;
            pos.next = pre;
            pre = pos;
            pos = temp;
        }
        start.next.next = pos;
        start.next = pre;
        return dummy.next;
    }
}