/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    排序只有三种元素的数组
 */

class Solution {
    public void sortColors(int[] nums) {
        int p1 = 0, p2 = nums.length - 1, index = 0;
        while (index <= p2) {
            if (nums[index] == 0) {
                nums[index] = nums[p1];
                nums[p1] = 0;
                p1++;
            }
            if (nums[index] == 2) {
                nums[index] = nums[p2];
                nums[p2] = 2;
                p2--;
                index--;
            }
            index++;
        }
    }
}