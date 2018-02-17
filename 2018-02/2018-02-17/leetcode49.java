/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    给一组字符串每个字符按组成分类。map 的使用。
 */


class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        
        for(int i = 0; i < strs.length; i++)
        {
            char[] ca = strs[i].toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!mp.containsKey(key)) mp.put(key, new ArrayList<String>());
            mp.get(key).add(strs[i]);
        }
        
        return new ArrayList<List<String>>(mp.values());
    }
}
