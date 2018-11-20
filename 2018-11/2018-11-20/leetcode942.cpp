class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.length();
        vector<int> res(n + 1, 0);
        
        int big = n;
        for (int i = 1; i <= n - 1; i++) {
            if (S[i - 1] == 'I' && S[i] == 'D') {
                res[i] = big--;
            }
        }
        
        int small = 0;
        for (int i = 0; i < n; i++) {
            if (!res[i]) {
                res[i] = S[i] == 'I' ? small++ : big--;
            }
        }
        res[n] = big;
        return res;
    }
};