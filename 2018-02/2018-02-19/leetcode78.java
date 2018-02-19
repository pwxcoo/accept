/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    寻找 s 中最短的包含 t 字符串所有字符的字串。
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
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList<Integer>(), nums, 0);
        return res;
    }
}