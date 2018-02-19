/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(log(n)), worse = O(n) S = O(1)
 * describe:    二分搜索。重复的时候right--,直接下一个循环。
 */


class Solution {
    public boolean search(int[] nums, int target) {
        if(nums.length == 0) return false;
        int left = 0, right = nums.length - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            
            if(nums[mid] > nums[right]) //left is sorted
            {
                if(target < nums[left] || target > nums[mid]) left = mid + 1;
                else right = mid;
            }
            else if(nums[mid] < nums[right]) //right is sorted
            {
                if(target < nums[mid] || target > nums[right]) right = mid;
                else left = mid + 1;
            }
            else right--;
        }
        return nums[left] == target;
    }
}