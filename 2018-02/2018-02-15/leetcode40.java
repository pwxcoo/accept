/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n^n), S = O(n^n)
 * describe:    dfs
 */

class Solution {
    void dfs(List<List<Integer>> res, List<Integer> cur, int[] candidates, int target, int start)
    {
        if(target < 0) return;
        
        for(int i = start; i < candidates.length; i++)
        {
            if(target - candidates[i] < 0) return;
            else if(target - candidates[i] == 0)
            {
                cur.add(candidates[i]);
                res.add(new ArrayList(cur));
                cur.remove(cur.size() - 1);
            }
            else
            {
                cur.add(candidates[i]);
                dfs(res, cur, candidates, target - candidates[i], i + 1);
                cur.remove(cur.size() - 1);
            }
            while(i + 1 < candidates.length && candidates[i] == candidates[i + 1]) i++;
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList(), candidates, target, 0);
        return res;
    }
}