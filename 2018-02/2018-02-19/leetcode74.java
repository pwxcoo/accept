/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(nm), S = O(1)
 * describe:    扫描排序过的矩阵
 */

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length - 1, col = 0;
        
        while(row >= 0 && col < matrix[0].length)
        {
            if(target > matrix[row][col]) col++;
            else if(target < matrix[row][col]) row--;
            else return true;
        }
        
        return false;
    }
}