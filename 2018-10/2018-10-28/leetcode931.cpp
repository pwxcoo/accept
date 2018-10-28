class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                int best = A[i + 1][j];
                if (j > 0)
                    best = min(best, A[i + 1][j - 1]);
                if (j < m - 1)
                    best = min(best, A[i + 1][j + 1]);
                A[i][j] += best;
            }
        }
        
        int res = A[0][0];
        for (int i = 1; i < m; i++)
            res = min(res, A[0][i]);
        return res;
    }
};