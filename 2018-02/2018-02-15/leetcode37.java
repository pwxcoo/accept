/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    回溯。回溯不能 void 所以再弄一个有返回值的运算函数。
 */

class Solution {
    public boolean isValid(char[][] board, int n, int m) {
        for(int i = 0; i < 9; i++)
        {
            if(n != i && board[i][m] == board[n][m]) return false;
            if(m != i && board[n][i] == board[n][m]) return false;
        }
        
        for(int i = n / 3 * 3; i < n / 3 * 3 + 3; i++)
        {
            for(int j = m / 3 * 3; j < m / 3 * 3 + 3; j++)
            {
                if(i != n && j != m && board[i][j] == board[n][m]) return false;
            }
        }
        
        return true;
    }
    
    boolean solve(char[][] board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int u = 0; u < 9; u++)
                    {
                        board[i][j] = (char)('1' + u);
                        if(isValid(board, i, j) && solve(board)) return true;
                        else board[i][j] = '.';
                    }
                    if(board[i][j] == '.') return false;
                }
            }
        }
        return true;
    }
    
    public void solveSudoku(char[][] board) {
        solve(board);
    }
}