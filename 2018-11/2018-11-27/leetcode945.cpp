class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size(); if (!n) return 0;
        
        sort(A.begin(), A.end());
        
        int need = A[0] + 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            res += max(need - A[i], 0);
            need = max(A[i], need) + 1;
        }
        return res;
    }
};