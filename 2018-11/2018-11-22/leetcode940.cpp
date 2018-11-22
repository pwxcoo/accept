class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string S) {
        int len = S.length();
        
        long long res = 0;
        vector<long long> cnt(26, 0);
        for (int i = 0; i < len; i++) {
            long long temp = res - cnt[S[i] - 'a'];
            cnt[S[i] - 'a'] = (res + 1) % mod;
            res = (temp + cnt[S[i] - 'a']) % mod;
        }
        return (res + mod) % mod;
    }
};