/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    最简单的DP
 */

class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0], temp = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            if(temp < 0) temp = 0;
            temp += nums[i];
            res = Math.max(temp, res);
        }
        return res;
    }
}