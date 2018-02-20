/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dp
 */

class Solution {
    public int numDecodings(String s) {
        if(s.length() == 0) return 0;
        int[] dp = new int[s.length() + 2];
        dp[0] = dp[1] = 1;
        for(int i = 0; i < s.length(); i++)
        {
            
            if(s.charAt(i) == '0')
            {// 0 statement. only 10, 20
                if(i > 0 && (s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2')) dp[i + 2] = dp[i];
                else dp[i + 2] = 0;
            }
            else if(s.charAt(i) >= '1' && s.charAt(i) <= '6')
            {// 1 - 6 , if previous element is 1 or 2, make more decode
                if(i > 0 && (s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2')) dp[i + 2] = dp[i + 1] + dp[i];
                else dp[i + 2] = dp[i + 1];
            }
            else if(s.charAt(i) >= '7' && s.charAt(i) <= '9')
            {// 7 - 9, if previous element is 1, make more decode
                if(i > 0 && s.charAt(i - 1) == '1') dp[i + 2] = dp[i + 1] + dp[i];
                else dp[i + 2] = dp[i + 1];
            }
            else dp[i + 2] = 0;
        }
        return dp[s.length() + 1];
    }
}