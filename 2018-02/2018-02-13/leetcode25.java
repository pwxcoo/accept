/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    交换链表 k 个结点
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode res = dummy;
        
        /* count len, break if too short */
        int cnt = -1;
        while(dummy != null && cnt < k)
        {
            dummy = dummy.next;
            cnt ++;
        }
        if(cnt < k) return res.next;
        
        /* do reverse recursive */
        ListNode one, two;
        one = res.next;
        for(int i = 0; i < k - 1; i++)
        {
            two = one.next; 
            one.next = two.next;
            two.next = res.next;
            res.next = two;
        }
        one.next = reverseKGroup(dummy, k);
        
        return res.next;
    }
}