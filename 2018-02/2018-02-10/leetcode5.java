/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n)best, O(n^2)worst, S = O(1)
 * describe:    遍历寻找最长回文字串
 */

class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        int start = 0, res = 0;
        for(int i = 0; i < len; i++)
        {
            int left = i - 1;
            while(i + 1 < len && s.charAt(i + 1) == s.charAt(i)) i++;
            int right = i + 1;
            while(left >= 0 && right < len && s.charAt(left) == s.charAt(right))
            {
                left--;
                right++;
            }
            if(right - left - 1 > res)
            {
                res = right - left - 1;
                start = left + 1;
            }
        }
        return s.substring(start, start + res);
    }
}