/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    回文
 */

class Solution {
    private boolean isAlphanumeric(char a)
    {
        if(a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9') return true;
        return false;
    }
    
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while(left < right)
        {
               
            while(left < right && !isAlphanumeric(s.charAt(left))) left++;
            while(left < right && !isAlphanumeric(s.charAt(right)))  right--;
            if(left == right) break;
            if((s.charAt(left) | 32) != (s.charAt(right) | 32)) return false;
            left++; right--;
        }
        
        return true;
    }
}