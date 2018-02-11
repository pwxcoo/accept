/**
 * date: 2018-02-11
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    类似正则表达式引擎？用 dp 解决字符串匹配的问题。注意 ‘*’ 的状态转移有三个地方可以转移。
 */

class Solution {
    public boolean isMatch(String s, String p) {
        int slen = s.length(), plen = p.length();
        boolean[][] dp = new boolean[plen + 1][slen + 1];

        dp[0][0] = true;
        for(int i = 1; i <= plen; i++) dp[i][0] = p.charAt(i - 1) == '*' ? dp[i - 2][0] : false;
        for(int j = 1; j <= slen; j++) dp[0][j] = false;
        
        for(int i = 1; i <= plen; i++)
        {
            for(int j = 1; j <= slen; j++)
            {
                if(p.charAt(i - 1) == s.charAt(j - 1) || p.charAt(i - 1) == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p.charAt(i - 1) == '*')
                {
                    dp[i][j] = dp[i - 2][j] || dp[i - 1][j];
                    if(dp[i][j - 1] == true && (p.charAt(i - 2) == s.charAt(j - 1) || p.charAt(i - 2) == '.'))
                    {
                        dp[i][j] = true;
                    }
                }
                else dp[i][j] = false;
            }
        }
        
        return dp[plen][slen];
    }
}