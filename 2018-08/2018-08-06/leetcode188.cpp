class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || k == 0) return 0;
        if (len / 2 <= k) return handleBigK(prices); 
        
        vector<vector<int>> dp(k + 1, vector<int>(len, 0));
        
        /* dp[T][i] = max(dp[T][i - 1], prices[i] - prices[j] + dp[T - 1][j - 1]), j = [0, i - 1] */
        for (int t = 1; t <= k; t++)
        {
            int min_before = prices[0];
            for (int i = 1; i < len; i++)
            {
                dp[t][i] = max(dp[t][i - 1], prices[i] - min_before);
                min_before = min(min_before, prices[i] - dp[t - 1][i - 1]);
            }
        }
        
        return dp[k][len - 1];
    }
    
    int handleBigK(vector<int>& prices)
    {
        int total = 0;
        for (int i = 0; i + 1 < prices.size(); i++)
        {
            if (prices[i + 1] > prices[i]) 
                total += prices[i + 1] - prices[i];
        }
        return total;
    }
};