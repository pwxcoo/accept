/**
 * date: 2018-02-21
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    dp
 */

class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s2.length(), m = s1.length(), len = s3.length();
        if(n + m != len) return false;
        boolean[][] dp = new boolean[n + 1][m + 1];
        dp[0][0] = true;
        int temp = 0;
        while(temp < m && s1.charAt(temp) == s3.charAt(temp)) dp[0][++temp] = true;
        temp = 0;
        while(temp < n && s2.charAt(temp) == s3.charAt(temp)) dp[++temp][0] = true;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(dp[i][j - 1] && s1.charAt(j - 1) == s3.charAt(i + j - 1) || 
                    dp[i - 1][j] && s2.charAt(i - 1) == s3.charAt(i + j - 1)) 
                    dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
}