/**
 * date: 2018-02-23
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    dp,二维数组
 */

class Solution {
    public int minCut(String s) {
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        int[] dp = new int[s.length() + 1];
        for(int i = 0; i <= s.length(); i++) dp[i] = s.length() - i - 1;
        
        for(int i = s.length() - 1; i >= 0; i --)
        {
            isPalindrome[i][i] = true;
            dp[i] = dp[i + 1] + 1;
            for(int j = i + 1; j < s.length(); j++)
            {
                if(s.charAt(i) == s.charAt(j) && (i + 1 == j || isPalindrome[i + 1][j - 1]))
                {
                    isPalindrome[i][j] = true;
                    if(dp[j + 1] + 1 < dp[i])
                    {
                        dp[i] = dp[j + 1] + 1;
                    }
                }
                

            }
        }
        return dp[0];
    }
}

/**
 * date: 2018-02-23
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n)
 * describe:    dp，一维数组
 */
class Solution {
    public int minCut(String s) {
        int[] dp = new int[s.length() + 1];
        for(int i = 0; i <= s.length(); i++) dp[i] = i - 1;
        
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = 0; i - j >= 0 && i + j < s.length() && s.charAt(i - j) == s.charAt(i + j); j++) // odd 
                dp[i + j + 1] = Math.min(dp[i + j + 1], dp[i - j] + 1);
            for(int j = 0; i - j - 1 >= 0 && i + j < s.length() && s.charAt(i - j - 1) == s.charAt(i + j); j++)
                dp[i + j + 1] = Math.min(dp[i + j + 1], dp[i - j - 1] + 1);
        }
        return dp[s.length()];
    }
}