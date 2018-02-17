/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    边界情况的处理
 */

class Solution {
    public int lengthOfLastWord(String s) {
        int res, start = s.length() - 1;
        while(start >= 0 && s.charAt(start) == ' ') start--;
        res = start;
        while(res >= 0 && s.charAt(res) != ' ') res--;
        return start - res;
    }
}