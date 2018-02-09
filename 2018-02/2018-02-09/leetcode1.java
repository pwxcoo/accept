/**
 * date: 2018-02-09
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    寻找一个数组里是否有两个数的和为一个目标数。
 *              遍历的时候用一个map记录已经遍历过数的下标。
 *              每次遍历到新的数字则在map里查找，HashMap查找效率O(1)，查找到直接返回结果。
 */
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++)
        {
            int complement = target - nums[i];
            if(map.containsKey(complement))
            {
                return new int[] {map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
