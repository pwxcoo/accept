/**
 * date: 2018-02-16
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    贪心
 */

class Solution {
    public int jump(int[] nums) {
        int cnt = 0, now = 0;
        if(nums.length <= 1) return cnt;
        while(now + nums[now] < nums.length - 1)
        {
            int next = now;
            for(int i = now; i <= now + nums[now]; i++)
            {
                if(i + nums[i] > next + nums[next]) next = i;
            }
            now = next;
            cnt++;
        }
        return cnt + 1;
    }
}