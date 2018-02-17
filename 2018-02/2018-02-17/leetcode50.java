/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(log(n)), S = O(1)
 * describe:    实现 pow（x，n）。利用二分，注意保存奇数时的值。
 */


class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if(N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1, current_product = x;
        for(long i = N; i > 0; i /= 2)
        {
            if((i % 2) == 1)
            {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
}   