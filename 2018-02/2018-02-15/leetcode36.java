/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    用 map 保存状态。可以用数组直接模拟 map
 */

class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] rows = new int[9][9]; 
        int[][] cols = new int[9][9];
        int[][] parts = new int[9][9];
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(rows[i][board[i][j] - '1'] == 1) return false;
                    else rows[i][board[i][j] - '1'] = 1;
                    if(cols[j][board[i][j] - '1'] == 1) return false;
                    else cols[j][board[i][j] - '1'] = 1;
                    if(parts[i / 3 * 3 + j / 3][board[i][j] - '1'] == 1) return false;
                    else parts[i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
                }
            }
        }
        
        return true;
    }
}