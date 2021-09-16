class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return vector<int>(0);
        }
        
        int m = matrix[0].size();
        vector<int>res(n * m);
        
        int left = 0, right = m - 1, up = 0, down = n - 1;
        int now = 0;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                res[now++] = matrix[up][i];
            }
            if (++up > down) break;
            for (int i = up; i <= down; i++) {
                res[now++] = matrix[i][right];
            }
            if (--right < left) break;
            for (int i = right; i >= left; i--) {
                res[now++] = matrix[down][i];
            }
            if (--down < up) break;
            for (int i = down; i >= up; i--) {
                res[now++] = matrix[i][left];
            }
            if (++left > right) break;
        }
        return res;
    }
};