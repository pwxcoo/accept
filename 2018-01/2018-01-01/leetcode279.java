class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            
            for(int j = 1; j  <= i / j; j++)
            {
                if(j * j == i)
                {
                    dp[i] = 1;
                    break;
                }
                dp[i] = Math.min(dp[i], dp[j * j] + dp[i - j * j]);
            }
        }
        return dp[n];
    }
}