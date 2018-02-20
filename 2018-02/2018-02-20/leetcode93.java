/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    生成 ip 地址
 */

class Solution {
    void dfs(List<String> res, int now, List<String> cur, String s) {
        if(now == 4)
        {
            if(s.isEmpty())
            {
                res.add(String.join(".", cur));
                return;
            }
            else return;
        }
        if(now > 4 || s.isEmpty()) return;

          
        int temp = 0;
        for(int i = 0; i < 3 && i < s.length(); i++)
        {
            if(i == 0 && s.charAt(i) == '0')
            {
                cur.add("0");
                dfs(res, now + 1, cur, s.substring(i + 1));
                cur.remove(cur.size() - 1);
                return;
            }
            else
            {
                temp = temp * 10 + (s.charAt(i) - '0');
                if(temp > 255 || temp < 0) return;
                cur.add(s.substring(0, i + 1));
                dfs(res, now + 1, cur, s.substring(i + 1));
                cur.remove(cur.size() - 1);
            }
        }
    }
    
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        dfs(res, 0, new ArrayList<String>(), s);
        return res;
    }
}