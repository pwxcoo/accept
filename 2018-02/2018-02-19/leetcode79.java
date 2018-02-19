/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n*m), S = O(n*m)
 * describe:    dfs, 回溯
 */

class Solution {
    final int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    boolean find(char[][] board, boolean[][] visit, String word, int row, int col)
    {
        if(word.length() == 0) return true;
        visit[row][col] = true;
        for(int i = 0; i < 4; i++)
        {
            int nextr = row + dir[i][0];
            int nextc = col + dir[i][1];
            if(nextr < 0 || nextr >= board.length || nextc < 0 || nextc >= board[0].length) continue;
            if(visit[nextr][nextc] == false && board[nextr][nextc] == word.charAt(0) && find(board, visit, word.substring(1), nextr, nextc)) return true;
        }
        visit[row][col] = false;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        boolean[][] visit = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                if(board[i][j] == word.charAt(0) && find(board, visit, word.substring(1), i, j)) return true;
            }
        }
        return false;
    }
}