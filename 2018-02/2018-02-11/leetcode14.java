/**
 * date: 2018-02-11
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    求一组字符串的最长前缀字符串。直接求。
 */

class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len = strs.length;
        if(len == 0) return "";
        
        StringBuffer sb = new StringBuffer();
        int cnt = 0;
        while(true)
        {
            boolean flag = true;
            if(cnt >= strs[0].length()) break;
            
            for(int i = 1; i < len; i++)
            {
                if( cnt >= strs[i].length() || strs[i].charAt(cnt) != strs[0].charAt(cnt)) 
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag) sb.append(strs[0].charAt(cnt++));
            else break;
        }
        
        return sb.toString();
    }
}