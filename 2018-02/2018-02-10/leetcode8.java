/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    atio() 函数的实现。注意空格，符号，溢出
 */

class Solution {
    public int myAtoi(String str) {
        int index = 0, sign = 1, total = 0, len = str.length();
        //remove space 
        while(index < len && str.charAt(index) == ' ')  index++;
        
        //handle sign
        if(index < len && (str.charAt(index) == '+' || str.charAt(index) == '-'))
        {
            sign = str.charAt(index) == '+' ? 1 : -1;
            index++;
        }
        
        //convert number and avoid overflow
        while(index < len)
        {
            int digit = str.charAt(index) - '0';
            if(digit < 0 || digit > 9) break;
            
            if(Integer.MAX_VALUE / 10 < total || (Integer.MAX_VALUE / 10 == total && Integer.MAX_VALUE % 10 < digit))
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            
            total = total * 10 + digit;
            index++;
        }
        return total * sign;   
    }
}