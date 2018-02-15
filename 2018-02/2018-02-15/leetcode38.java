/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    字符串操作
 */

class Solution {
    public String countAndSay(int n) {
        StringBuffer now = new StringBuffer("1");
        StringBuffer temp;
        for(int i = 1; i < n; i++)
        {
            temp = new StringBuffer("");
            for(int j = 0; j < now.length(); j++)
            {
                int cnt = 1;
                while(j + 1 < now.length() && now.charAt(j) == now.charAt(j + 1)) 
                {
                    cnt++;
                    j++;
                }
                temp.append(cnt);
                temp.append(now.charAt(j));
            }
            now = temp;
        }
        return now.toString();
    }
}