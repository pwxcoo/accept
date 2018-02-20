/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n)
 * describe:    递归
 */

class Solution {
    public boolean isScramble(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        int len = s1.length();
        if(len <= 1) return s1.equals(s2);
        int[] c = new int[128];
        for(int i = 0; i < s1.length(); i++) c[s1.charAt(i)]++;
        for(int i = 0; i < s2.length(); i++) c[s2.charAt(i)]--;
        for(int i = 0; i < 128; i++) if(c[i] != 0) return false;
         
        for(int i = 1; i < len; i++)
        {
            if((isScramble(s1.substring(i), s2.substring(i)) && isScramble(s1.substring(0,i), s2.substring(0,i))) ||
                (isScramble(s1.substring(0, i), s2.substring(len - i)) && isScramble(s1.substring(i), s2.substring(0, len - i))))
                return true;
        }
        return false;
    }
}