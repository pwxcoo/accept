/**
 * 记录 L-R 的情况，大于 R 就要重新计数，小于 L 的不算，所以处理的时候要减去小于 L 的情况。
 */
class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }
    
    static int count(int[] A, int bound)
    {
        int res = 0, cur = 0;
        for(int x: A)
        {
            cur = x <= bound ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
}