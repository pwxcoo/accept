/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    异或操作，毁天灭地
 */

class Solution {
    public int singleNumber(int[] nums) {
        int temp = 0;
        for(int num : nums) temp ^= num;
        return temp;
    }
}