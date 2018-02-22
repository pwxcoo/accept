/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dfs 回溯
 */

class Solution {
    boolean isOk(String s)
    {
        int left = 0, right = s.length() - 1;
        while(left < right)
        {
            if(s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }
    
    void dfs(List<List<String>> res, List<String> cur, String s)
    {
        if(s.length() == 0) 
        {
            res.add(new ArrayList<String>(cur));
            return;
        }
        
        for(int i = 1; i <= s.length(); i++)
        {
            String temp = s.substring(0, i);
            if(isOk(temp))
            {
                cur.add(temp);
                dfs(res, cur, s.substring(i));
                cur.remove(cur.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        dfs(res, new ArrayList<String>(), s);
        return res;
    }
}