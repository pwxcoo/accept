/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n^m), S = O(1)
 * describe:    dp
 */

class Solution {
    public int minPathSum(int[][] grid) {
        if(grid.length == 0 || grid[0].length == 0) return 0;
        
        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[0].length; j++)
            {
                if(i == 0 && j == 0) grid[i][j] = grid[i][j];
                else if(i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if(j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
                else grid[i][j] = Math.min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        
        return grid[grid.length - 1][grid[0].length - 1];
    }
}