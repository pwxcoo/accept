/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(nm), S = O(1)
 * describe:    dfs + bfs
 */

class Solution {
    int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(char[][] board, int n, int m)
    {
        if(board[n][m] != 'O') return;
        
        board[n][m] = '*';
        for(int i = 0; i < 4; i++)
        {
            int r = n + dir[i][0];
            int c = m + dir[i][1];
            
            if(r < 0 || r >= board.length || c < 0 || c >= board[0].length) continue;
            if(board[r][c] == 'O') dfs(board, r, c);
        }
    }
    
    public void solve(char[][] board) {
        if(board.length == 0 || board[0].length == 0) return;
        for(int i = 0; i < board[0].length; i++)
        {
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[board.length - 1][i] == 'O') dfs(board, board.length - 1, i);
        }
        
        for(int i = 0; i < board.length; i++)
        {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][board[0].length - 1] == 'O') dfs(board, i, board[0].length - 1);
        }
                        
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
}