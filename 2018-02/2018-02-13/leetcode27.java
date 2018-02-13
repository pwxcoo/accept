/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    移除数组中某个元素
 */

class Solution {
    public int removeElement(int[] nums, int val) {
        int res = 0;
        for(int n : nums)
        {
            if(n != val) nums[res++] = n;
        }
        return res;
    }
}