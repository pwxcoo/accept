class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int n = A.size();

        sort(A.begin(), A.end());

        int mn = 0x7fffffff;
        for (int i = 0; i < n && K > 0; i++, K--) {
            mn = min(mn, abs(A[i]));

            if (A[i] > 0) break;
            else A[i] = -A[i];
        }

        K %= 2;
        if (K) mn = -2 * mn;
        else mn = 0;

        return accumulate(A.begin(), A.end(), mn);
    }
};