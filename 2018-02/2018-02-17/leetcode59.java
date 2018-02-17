/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    zigzag矩阵
 */

class Solution {
    public int[][] generateMatrix(int n) {
        int now = 1;
        
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int[][] res = new int[n][n];
        while(true)
        {
            for(int i = left; i <= right; i++)
                res[up][i] = now++;;
            if(++up > down) break;
            for(int i = up; i <= down; i++)
                res[i][right] = now++;
            if(--right < left) break;
            for(int i = right; i >= left; i--)
                res[down][i] = now++;
            if(--down < up) break;
            for(int i = down; i >= up; i--)
                res[i][left] = now++;
            if(++left > right) break;
        }
        return res;
    }
}