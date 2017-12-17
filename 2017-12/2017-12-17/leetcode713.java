class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int len = nums.length;
        int left = 0, sum = 1, res = 0;
        for(int i = 0; i < len; i++)
        {
            sum *= nums[i];
            while(sum >= k && left <= i)
            {
                sum /= nums[left++];
            }
            res += i - left + 1;
        }
        return res;
    }
}