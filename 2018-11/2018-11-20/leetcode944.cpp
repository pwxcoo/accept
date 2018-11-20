class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int len = A[0].length();
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < n; j++) {
                if (A[j][i] < A[j - 1][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};