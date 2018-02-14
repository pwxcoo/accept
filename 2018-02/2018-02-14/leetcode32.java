/**
 * date: 2018-02-14
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    动态规划。
 */

class Solution {
    public int longestValidParentheses(String s) {
        int len = s.length();
        int[] dp = new int[len];
        int res = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(i - 1 >= 0 && s.charAt(i) == ')')
            {
                if(s.charAt(i - 1) == '(') 
                {
                    if(i >= 2) dp[i] = dp[i - 2] + 2;
                    else dp[i] = 2;
                }
                else if(s.charAt(i - 1) == ')')
                {
                    if(i - 1 - dp[i - 1] >= 0 && s.charAt(i - 1 - dp[i - 1]) == '(') 
                    {
                        dp[i] = dp[i - 1] + 2;
                        if(i - 2 - dp[i - 1] >= 0) dp[i] += dp[i - 2 - dp[i - 1]];
                    }
                }
                res = Math.max(res, dp[i]);
            }
        }
        
        return res;
    }
}