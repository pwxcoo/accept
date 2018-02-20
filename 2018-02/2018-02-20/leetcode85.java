/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    最大非零矩阵问题
 */

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) return 0;
        int[][] c = new int[matrix.length][matrix[0].length];
        
        int res = 0;
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = 0; j < matrix[0].length; j++)
            {
                if(matrix[i][j] == '1')
                {
                    c[i][j] = j > 0 ? c[i][j - 1] + 1 : 1;
                    
                    int up = i, temp = c[i][j];
                
                    while(up >= 0 && c[up][j] > 0)
                    {
                        temp = Math.min(temp, c[up][j]);
                        res = Math.max(res, (i - up + 1) * temp);
                        up--;
                    }
                }
                

            }
        }
        
        return res;
    }
}