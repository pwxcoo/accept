/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    要求用 O（1）的空间，所以要利用原数组保存结果。
 */

class Solution {
    public int firstMissingPositive(int[] nums) {
        
        for(int i = 0; i < nums.length; )
        {
            if(nums[i] <= 0 || nums[i] > nums.length) i++;
            else if(nums[i] != nums[nums[i] - 1]) swap(i, nums[i] - 1, nums);
            else i++;
        }
        
        int res = 0;
        while(res < nums.length)
        {
            if(nums[res] != res + 1) return res + 1;
            res ++;
        }
        return res + 1;
    }
    
    void swap(int i, int j, int[] nums)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}