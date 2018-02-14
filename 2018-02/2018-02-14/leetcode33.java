/**
 * date: 2018-02-14
 * author: pwxcoo
 * complexity: T = O(log(n)), S = O(1)
 * describe:    二分查找。有一边是有序的，判断边界确定 target 在哪边求解。
 */

class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        if(len == 0) return -1;
        
        int low = 0, high = len - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] < nums[high])  // right part is sorted
            {
                if(target <= nums[mid] || target > nums[high])
                {
                    high = mid;
                }
                else low = mid + 1;
            }
            else    //left part is sorted
            {
                if(target < nums[low] || target > nums[mid])
                {
                    low = mid + 1;
                }
                else high = mid;
            }
        }
        
        return target == nums[low] ? low : -1;
        
    }
}