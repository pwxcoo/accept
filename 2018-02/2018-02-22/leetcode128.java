/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    智商题
 */

class Solution {
    public int longestConsecutive(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        int res = 0;
        for(int num : nums)
        {
            if(!counts.containsKey(num))
            {
                int left = counts.getOrDefault(num - 1, 0);
                int right = counts.getOrDefault(num + 1, 0);
                int val = left + right + 1;
                res = Math.max(res, val);
                counts.put(num, val);
                counts.put(num - left, val);
                counts.put(num + right, val);
            }
        }
        
        return res;
    }
}