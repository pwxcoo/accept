/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    判断一个整数是否为回文。注意溢出。
 */

class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        int reverse = 0;
        while(reverse < x)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        
        return reverse == x || reverse / 10 == x;
    }
}