/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    得到有序数组的 unique 的个数
 */


class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;
        int res = 0;
        for(int i = 1; i < nums.length; i++)
        {
            if(nums[i] != nums[res]) 
                nums[++res] = nums[i];
        }
        return res + 1;
    }
}