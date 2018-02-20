/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    dfs
 */

class Solution {
    void dfs(List<List<Integer>> res, List<Integer> cur, int[] nums, int now)
    {
        res.add(new ArrayList<Integer>(cur));
        for(int i = now; i < nums.length; i++)
        {
            cur.add(nums[i]);
            dfs(res, cur, nums, i + 1);
            cur.remove(cur.size() - 1);
            while(i + 1 < nums.length && nums[i + 1] == nums[i]) i++;
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList<Integer>(), nums, 0);
        return res;
    }
}