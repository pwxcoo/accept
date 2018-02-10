/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    用一个滑动窗口来遍历字符串从而获得最大的字串
 */

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] c = new int[256];
        Arrays.fill(c, -1);
        int res = 0, begin = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(c[s.charAt(i)] < begin)
            {
                res = Math.max(res, i - begin + 1);
            }
            else
            {
                begin = c[s.charAt(i)] + 1;
            }
            c[s.charAt(i)] = i;
        }
        return res;
    }
}