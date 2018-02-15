/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    很技巧的一道题。用两个指针向中间收敛，维护一个短板高度，收敛过程中变高就增加短板高度，变低就得到水的量。
 */

class Solution {
    public int trap(int[] height) {
        if(height.length <= 2) return 0;
        int left = 0, right = height.length - 1;
        int res = 0, level = Math.min(height[left], height[right]);
        
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                left++;
                if(height[left] > level)
                {
                    level = Math.min(height[left], height[right]);
                }
                else 
                {
                    res += level - height[left];
                }
            }
            else 
            {
                right--;
                if(height[right] > level)
                {
                    level = Math.min(height[left], height[right]);
                }
                else 
                {
                    res += level - height[right];
                }
            }
        }
        return res;
        
    }
}