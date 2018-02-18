/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n^m), S = O(m^n)
 * describe:    dp
 */

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid.length == 0 || obstacleGrid[0].length == 0) return 0; 
        int[][] dp = new int[obstacleGrid.length + 1][obstacleGrid[0].length + 1];
        dp[1][0] = 1;
        for(int i = 1; i <= obstacleGrid.length; i++)
        {
            for(int j = 1; j <= obstacleGrid[0].length; j++)
            {
                if(obstacleGrid[i - 1][j - 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[obstacleGrid.length][obstacleGrid[0].length];
    }
}