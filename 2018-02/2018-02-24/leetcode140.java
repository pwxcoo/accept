/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dfs
 */

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> st = new HashSet<>();
        for(String word : wordDict) st.add(word);
        return dfs(s, st, new HashMap<String, List<String>>());
        
    }
    
    List<String> dfs(String s, Set<String> st, Map<String, List<String>> map)
    {
        if(map.containsKey(s)) return map.get(s);
        List<String> res = new ArrayList<>();
        if(s.length() == 0)
        {
            res.add("");
            return res;
        }
        
        for(int i = 1; i <= s.length(); i++)
        {
            if(st.contains(s.substring(0, i)))
            {
                List<String> subList = dfs(s.substring(i), st, map);
                for(String sub : subList)
                {
                    res.add(s.substring(0, i) + (sub.length() == 0 ? "" : " " + sub));
                }
            }
        }
        map.put(s, res);
        return res;
    }
}