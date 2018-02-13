/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n*logk), S = O(1)
 * describe:    分治，合并 k 个链表转化为 n 个合并两个链表问题。
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
    public ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if(len == 0) return null;
        int left = 0, right = len - 1;
        
        while(left < right)
        {
            while(left < right)
            {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                left++; right--;
            }
            left = 0;
        }
        
        return lists[0];
    }
    
    ListNode mergeTwoLists(ListNode one, ListNode two)
    {
        ListNode head = new ListNode(0);
        ListNode pos = head;
        
        while(one != null && two != null)
        {
            if(one.val < two.val)
            {
                pos.next = one;
                one = one.next;
            }
            else
            {
                pos.next = two;
                two = two.next;
            }
            pos = pos.next;
        }
        
        if(one == null) pos.next = two;
        else pos.next = one;
        
        return head.next;
    }
}