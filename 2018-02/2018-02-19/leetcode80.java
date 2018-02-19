/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    双指针
 */

class Solution {
    public int removeDuplicates(int[] nums) {
        int res = 0, pos = 0, cnt = 1;
        if(nums.length == 0) return 0;
        for(int i = 1; i < nums.length; i++)
        {
            if(nums[i] == nums[res])
            {
                if(cnt >= 2) continue;
                else 
                {
                    nums[++res] = nums[i];
                    cnt++;
                }
            }
            else
            {
                nums[++res] = nums[i];
                cnt = 1;
            }
        }
        return res + 1;
    }
}