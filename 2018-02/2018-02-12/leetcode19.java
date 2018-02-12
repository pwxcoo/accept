/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    一次遍历移除链表倒数第N个字符串。定义一个伪头指针处理。
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode before = head, now = head;
        ListNode pre = new ListNode(0); 
        pre.next = head;
        ListNode res = pre;
        
        for(int i = 0; i < n; i++)
        {
            before = before.next;
        }
        
        
        while(before != null)
        {
            now = now.next;
            pre = pre.next;
            before = before.next;
        }
        
        pre.next = now.next;
        return res.next;
    }
}