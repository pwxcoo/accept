/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(nm), S = O(1)
 * describe:    数组操作。利用已给数组降低空间复杂度
 */

class Solution {
    public void setZeroes(int[][] matrix) {
        
        boolean row = false, col = false;
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = 0; j < matrix[0].length; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0 && j == 0)
                    {
                        row = true;
                        col = true;
                    }
                    else if(i == 0) row = true;
                    else if(j == 0) col = true;
                    else 
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
                
            }
        }
        
        for(int i = 1; i < matrix.length; i++)
        {
            for(int j = 1; j < matrix[0].length; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
                
            }
        }
        
        if(row) for(int i = 0; i < matrix[0].length; i++) matrix[0][i] = 0;
        if(col) for(int i = 0; i < matrix.length; i++) matrix[i][0] = 0;
    }
}