/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(1), S = O(1)
 * describe:    不用除法，取余运算除法。
 *              第一反应用加法模拟。但是除数很小效率很低。
 *              转化一下用二进制的思路。dividend = divisor * (1*a + 2*b, 4*c, 8*d...)。求解abcd..
 *              注意符号和溢出的问题。
 */

class Solution {
    public int divide(int dividend, int divisor) {
        /* consider when zero */
        if(divisor == 0) return Integer.MAX_VALUE;
        if(dividend == 0) return 0;
        
        /* caculate sign and remove it */
        long sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1; 
        long ldividend = Math.abs((long)dividend);
        long ldivisor = Math.abs((long)divisor);
        
        /* caculate it by using bit manipulation */
        long sum = 0;
        while(ldividend >= ldivisor)
        {
            long b = 1;
            while((b << 1) * ldivisor < ldividend)
            {
                b <<= 1;
            }
            ldividend -= b * ldivisor;
            sum += b;
        }
        
        /* check overflow */
        sum *= sign;
        if(sum > Integer.MAX_VALUE || sum < Integer.MIN_VALUE) return Integer.MAX_VALUE;
        else return (int)sum;     
    }
}