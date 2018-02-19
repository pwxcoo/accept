/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    去除链表中重复结点。
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy, pos = head;
        if(head == null) return head;
        pos = pos.next; pre = pre.next;
        while(pos != null)
        {
            if(pos.val == pre.val)
            {
                pos = pos.next;
                pre.next = pos;
            }
            else
            {
                pre = pre.next;
                pos = pos.next;
            }
        }
        return dummy.next;
    }
}