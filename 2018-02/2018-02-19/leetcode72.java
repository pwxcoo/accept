/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(nm), S = O(nm)
 * describe:    dp
 */

class Solution {
    public int minDistance(String word1, String word2) {
        int n = word2.length(), m = word1.length();
        int[][] dp = new int[n + 1][m + 1];
        
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1.charAt(j - 1) != word2.charAt(i - 1)) dp[i][j] += Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                else dp[i][j] = dp[i - 1][j - 1];
            }
        }
        
        return dp[n][m];
    }
}