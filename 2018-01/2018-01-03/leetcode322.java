class Solution {
    public int coinChange(int[] coins, int amount) {
        int len = coins.length;
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            dp[i] = -1;
            for(int j = 0; j < len; j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                {
                    dp[i] = dp[i] == -1 ? (1 + dp[i - coins[j]]) : Math.min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return dp[amount];
    }
}