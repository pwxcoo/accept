/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    zigzag遍历字符串（可以使用 StringBuffer)
 */


class Solution {
    public String convert(String s, int numRows) {
        char[] c = s.toCharArray();
        int len = c.length;
        StringBuffer[] sb = new StringBuffer[numRows];
        for(int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();
        
        int i = 0;
        while(i < len)
        {
            for(int idx = 0; idx < numRows && i < len; idx++)
                sb[idx].append(c[i++]);
            for(int idx = numRows - 2; idx >= 1 && i < len; idx--)
                sb[idx].append(c[i++]);
        }
        for(int idx = 1; idx < sb.length; idx++)
            sb[0].append(sb[idx]);
        return sb[0].toString();
    }
}