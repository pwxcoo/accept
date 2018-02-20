/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    分类链表
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
    public ListNode partition(ListNode head, int x) {
        ListNode less = new ListNode(0);
        ListNode big = new ListNode(0);
        ListNode link = big, res = less;
        
        while(head != null)
        {
            if(head.val >= x)
            {
                big.next = head;
                big = big.next;
            }
            else
            {
                less.next = head;
                less = less.next;
            }
            head = head.next;
        }
        
        less.next = link.next;
        big.next = null;
        return res.next;
    }
}