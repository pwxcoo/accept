/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    位运算毁天灭地
 */

class Solution {
    public int singleNumber(int[] nums) {
        int one = 0, two = 0;
        for(int num : nums)
        {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
}