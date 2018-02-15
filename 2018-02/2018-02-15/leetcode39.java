/**
 * date: 2018-02-15
 * author: pwxcoo
 * complexity: T = O(n^n), S = O(n^n)
 * describe:    dfs。注意 java 中的引用。
 *              还可以用 dp 做。求出 [1, target] 的状态就可以了。
 */

class Solution {
    void dfs(List<List<Integer>> res, List<Integer> cur, int[] candidates, int now, int target)
    {
        if(target < 0) return;
        
        for(int i = now; i < candidates.length; i++)
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
                dfs(res, cur, candidates, i, target - candidates[i]);
                cur.remove(cur.size() - 1);
            }
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        dfs(res, cur, candidates, 0, target);
        return res;
    }
}