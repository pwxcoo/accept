/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    寻找 s 中最短的包含 t 字符串所有字符的字串。
 */


class Solution {
    public String minWindow(String s, String t) {
        int[] mp = new int[128];
        for(char c : t.toCharArray()) 
            mp[c]++;
        int start = 0, end = 0, head = 0, count = t.length(), d = Integer.MAX_VALUE;
        while(end < s.length())
        {
            if(mp[s.charAt(end++)]-- > 0) count--;
            while(count == 0)
            {
                if(end - start < d) d = end - (head = start);
                if(mp[s.charAt(start++)]++ == 0) count++;
            }
        }
        return d == Integer.MAX_VALUE ? "" : s.substring(head, head + d);
    }
}