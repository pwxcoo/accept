/**
 * date: 2018-02-11
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    从最长的底开始，移动较短边，试图将较短边增长，直到两边重合结束遍历。
 *              与暴力相比，减少的次数就是较长边向中间移动的次数
 */


class Solution {
    public int maxArea(int[] height) {
        int len = height.length;
        int left = 0, right = len - 1, res = 0;
        
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                res = Math.max(res, (right - left) * height[left]);
                left++;
            }
            else 
            {
                res = Math.max(res, (right - left) * height[right]);
                right--;
            }
        }
        return res;
    }
}