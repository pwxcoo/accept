/**
 * date: 2018-02-14
 * author: pwxcoo
 * complexity: T = O(log(n)), S = O(1)
 * describe:    二分查找。
 */

class Solution {
    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        
        int low = 0, high = len - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        
        return nums[low] >= target ? low : low + 1;
    }
}