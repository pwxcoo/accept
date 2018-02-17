/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    贪心
 */

class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length <= 1) return true;
        int now = 0;
        while(true)
        {
            if(now + nums[now] >= nums.length - 1) return true;
            int next = now;
            for(int i = now; i <= now + nums[now]; i++)
                if(nums[i] + i > nums[next] + next)
                    next = i;
            if(now == next) return false;
            now = next;
        }
    }
}