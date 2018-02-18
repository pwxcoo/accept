/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n^m), S = O(m^n)
 * describe:    dp
 */

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        dp[1][0] = 1;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
}