/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(1)
 * describe:    通过排序，双指针减少遍历次数。
 */


class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int len = nums.length;
        
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len; i++)
        {
            int left = i + 1, right = len - 1;
            
            while(left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if(temp > target) right--;
                else left++;
                
                if(Math.abs(temp - target) < Math.abs(res - target)) res = temp;
            }
        }
        
        return res;
    }
}