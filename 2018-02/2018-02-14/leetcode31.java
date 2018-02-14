/**
 * date: 2018-02-14
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    寻找全排列中下一个排列。就是找下一个增大的字典序排列。
 *              思路就是从尾部向前遍历，找一个减少的数字记为 i ，然后再次遍历找一个比 nums[i] 大的数字交换，然后重新排列 nums[i+1:] 部分
 */

class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        
        int right = len - 1;
        int cut = 0;
        for(int i = len - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                int j = len - 1;
                while(nums[j] <= nums[i]) j--;
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                cut = i + 1;
                break;
            }
        }
        Arrays.sort(nums, cut, len);
    }
}