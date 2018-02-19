/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n*k), S = O(n*k)
 * describe:    dfs
 */

class Solution {
    void dfs(List<List<Integer>> res, List<Integer> cur, int k, int now, int n)
    {
        if(cur.size() == k)
        {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for(int i = now; i <= n; i++)
        {
            cur.add(i);
            dfs(res, cur, k, i + 1, n);
            cur.remove(cur.size() - 1);
        }
    }
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList<>(), k, 1, n);
        return res;
    }
}