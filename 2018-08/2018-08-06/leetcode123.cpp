class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        
        int T = 2;
        vector<vector<int>> dp(T + 1, vector<int>(len, 0));
        for (int t = 1; t <= 2; t++)
        {
            int min_before = prices[0];
            for (int i = 1; i < len; i++)
            {
                dp[t][i] = max(dp[t][i - 1], prices[i] - min_before);
                min_before = min(min_before, prices[i] - dp[t - 1][i - 1]);
            }
        }
        
        return dp[2][len - 1];
    }
};