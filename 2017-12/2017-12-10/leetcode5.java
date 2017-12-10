class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        int start = 0;
        int maxlen = 0;
        for(int i = 0; i < len; i++)
        {
            int left = i - 1;
            int right = i + 1;
            while(right < len && s.charAt(right) == s.charAt(i)) right++;
            while(left >= 0 && right < len && s.charAt(left) == s.charAt(right)) { left--; right++; }
            if(right - left - 1 > maxlen)
            {
                start = left + 1;
                maxlen = right - left - 1;
            }
        }
        return s.substring(start, start + maxlen);
    }
}