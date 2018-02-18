/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    反转链表，注意超出长度和空指针的边界情况
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || k == 0) return head;
        int cnt = 0;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy, fast = head, slow = head;
        while(fast != null)
        {
            fast = fast.next;
            cnt++;
        }
        fast = head;
        k = k % cnt;
        while(k-- > 0) 
            fast = fast.next;
        
        while(fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }
        
        fast.next = dummy.next;
        dummy.next = slow.next;
        slow.next = null;
        return dummy.next;
    }
}