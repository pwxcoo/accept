/**
 * date: 2018-02-16
 * author: pwxcoo
 * complexity: T = O(n^n), S = O(n^n)
 * describe:    dfs。如果不用 visit 的话，只要把当前跟遍历到的 swap 一下就可以。
 */

class Solution {
    void dfs(List<List<Integer>> res, List<Integer> cur, int[] nums, boolean[] visit, int cnt)
    {
        if(cnt == nums.length)
        {
            res.add(new ArrayList<>(cur));
            return;
        }
        
        for(int i = 0; i < nums.length; i++)
        {
            if(visit[i] == false)
            {
                cur.add(nums[i]);
                visit[i] = true;
                dfs(res, cur, nums, visit, cnt + 1);
                visit[i] = false;
                cur.remove(cur.size() - 1);
            }
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[] visit = new boolean[nums.length];
        dfs(res, new ArrayList<>(), nums, visit, 0);
        return res;
    }
}