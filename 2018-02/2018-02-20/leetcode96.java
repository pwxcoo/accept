/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dp
 */

class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
}