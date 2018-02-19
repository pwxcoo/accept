/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    去除链表中有重复元素的结点。
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
        ListNode pos = head, pre = dummy;
        while(pos != null)
        {
            if(pos.next != null && pos.val == pos.next.val)
            {
                while(pos.next != null && pos.val == pos.next.val) pos.next = pos.next.next;
                pre.next = pos.next;
            }
            else pre = pos;
            pos = pos.next;
        }
        return dummy.next;
    }
}