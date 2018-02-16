/**
 * date: 2018-02-16
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    通配符匹配。DP。
 */

class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        if(m == 0 && n == 0) return true;
        boolean[][] dp = new boolean[n + 1][m + 1];
        
        dp[0][0] = true;
        int temp = 0;
        while(temp < n && p.charAt(temp) == '*') dp[++temp][0] = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s.charAt(j) == p.charAt(i))
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if(p.charAt(i) == '?')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if(p.charAt(i) == '*')
                {
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1] || dp[i][j];            
                }
            }
        }
        
        return dp[n][m];
    }
}