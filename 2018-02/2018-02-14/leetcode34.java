/**
 * date: 2018-02-14
 * author: pwxcoo
 * complexity: T = O(log(n)), S = O(1)
 * describe:    二分查找。找出下限和上限。
 */

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        int[] res = {-1, -1};
        if(len == 0) return res;
        
        int low = 0, high = len - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
        
            if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        
        if(nums[low] != target) return res;
        
        res[0] = low;
        
        low = 0; high = len - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
        
            if(nums[mid] < target || (nums[mid] == target && nums[mid + 1] == target)) low = mid + 1;
            else high = mid;
        }
        res[1] = high;
        
        return res;
        
    }
}