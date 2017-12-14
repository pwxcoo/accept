class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        boolean flag = true;
        int now = 0;
        for(int i = 0; i < len; i++)
        {
            if(i > now)
            {
                flag = false;
                break;
            } 
            if(nums[i] + i > now) now = nums[i] + i;
            if(now >= len) break;
        }
        return flag;
    }
}