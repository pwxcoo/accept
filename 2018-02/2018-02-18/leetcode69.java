/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    快速平方根。
 *              1. 二分查找 2. 牛顿迭代法
 */

class Solution {
    public int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = Integer.MAX_VALUE;
        while (true) {
            int mid = left + (right - left)/2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
}


/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    快速平方根。
 *              2. 牛顿迭代法
 */
class Solution {
    public int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return (int) r;
    }
}