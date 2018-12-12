    class Solution {
    public:
        int minDeletionSize(vector<string>& A) {
            int res = 0, n = A.size(), m = A[0].length(), i, j;

            bool finish = true;
            vector<bool> sorted(n-1, false);
            for (j = 0; j < m; ++j) {
                for (i = 0; i < n - 1; ++i) {
                    if (!sorted[i]) {
                        finish = false;
                        if (A[i][j] > A[i + 1][j]) {
                            res++;
                            break;
                        }
                    }
                }
                if (i < n - 1) continue;
                if (i == n - 1 && finish) break;
                for (i = 0; i < n - 1; ++i)
                    if (A[i][j] < A[i + 1][j])
                        sorted[i] = true;
            }
            return res;

        }
    };