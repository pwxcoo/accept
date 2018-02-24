/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dp
 */

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> st = new HashSet<>();
        for(String word : wordDict) st.add(word);
        
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++)
        {
            int left = i - 1;
            while(left >= 0)
            {
                if(dp[left]  && st.contains(s.substring(left, i)))
                {
                    dp[i] = true;
                    break;
                }
                left--;
            }
        }
        return dp[s.length()];
    }
}