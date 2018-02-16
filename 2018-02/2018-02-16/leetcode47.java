/**
 * date: 2018-02-16
 * author: pwxcoo
 * complexity: T = O(n^n), S = O(n^n)
 * describe:    dfs。跟 46 一样。加一个重复元素的判定舍去就好了。
 */

class Solution {    
    void dfs(List<List<Integer>> res, List<Integer> cur, int[] nums, boolean[] visit)
    {
        if(cur.size() == nums.length)
        {
            res.add(new ArrayList<>(cur));
            return;
        }
        
        for(int i = 0; i < nums.length; i++)
        {
            if(visit[i] == false)
            {
                visit[i] = true;
                cur.add(nums[i]);
                dfs(res, cur, nums, visit);
                cur.remove(cur.size() - 1);
                visit[i] = false;
                while(i + 1 < nums.length && nums[i] == nums[i + 1]) i++;
            }
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        boolean[] visit = new boolean[nums.length];
        dfs(res, new ArrayList<>(), nums, visit);
        return res;
    }
}