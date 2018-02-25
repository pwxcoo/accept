/**
 * date: 2018-02-25
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n)
 * describe:    插入排序
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
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode cur = head, pos;
        
        while(cur != null)
        {
            ListNode temp = cur.next;
            pos = dummy;
            while(pos.next != null && pos.next.val < cur.val)
            {
                pos = pos.next;
            }
            
            cur.next = pos.next;
            pos.next = cur;
            cur = temp;
        }
        
        return dummy.next;
    }
}