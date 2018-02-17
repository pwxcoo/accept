/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    模拟zigzag遍历矩阵   
 */

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length;
        if(m == 0) return res;
        int n = matrix[0].length;
        
        int up = 0, down = m - 1, left = 0, right = n - 1;

        while(true)
        {
            for(int i = left; i <= right; i++)
                res.add(matrix[up][i]);
            if(++up > down) break;
            for(int i = up; i <= down; i++)
                res.add(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--)
                res.add(matrix[down][i]);
            if(--down < up) break;
            for(int i = down; i >= up; i--)
                res.add(matrix[i][left]);
            if(++left > right) break;
        }
        
        return res;
    }
}