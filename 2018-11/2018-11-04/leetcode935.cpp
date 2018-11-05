class Solution {
public:
    int MOD = 1e9 + 7;
    int knightDialer(int N) {
        vector<long long> dp(10, 1);
        for (int i = 2; i <= N; i++) {
            vector<long long> next(10);
            next[0] = dp[4] + dp[6];
            next[1] = dp[6] + dp[8];
            next[2] = dp[7] + dp[9];
            next[3] = dp[4] + dp[8];
            next[4] = dp[3] + dp[9] + dp[0];
            next[5] = 0;
            next[6] = dp[1] + dp[7] + dp[0];
            next[7] = dp[2] + dp[6];
            next[8] = dp[1] + dp[3];
            next[9] = dp[2] + dp[4];
            for (int i = 0; i <= 9; i++)
                dp[i] = next[i] % MOD;
        }
        long long res = 0;
        for (int i = 0; i <= 9; i++)
            res = (res + dp[i]) % MOD;
        return res;
    }
};