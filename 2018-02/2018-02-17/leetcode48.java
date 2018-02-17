/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(1)
 * describe:    旋转矩阵，直接操作比较麻烦，可以先转置一波然后在每行reverse
 */

class Solution {
    public void rotate(int[][] matrix) {
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = i + 1; j < matrix[0].length; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i = 0; i < matrix.length; i++)   
        {
            int left = 0, right = matrix[0].length - 1;
            while(left < right)
            {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }
}