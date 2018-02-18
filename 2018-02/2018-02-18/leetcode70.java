/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    dp
 */


class Solution {
    public int climbStairs(int n) {
        if(n <= 2) return n;
        int one = 2, two = 1, now = 3, res = 0;
        while(now++ <= n)
        {
            res = one + two;
            two = one;
            one = res;
        }
        return res;
    }
}