/**
 * date: 2018-02-19
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    unix文件路径的简化
 */

class Solution {
    public String simplifyPath(String path) {
        int now = 0;
        List<String> p = new ArrayList<>();
        for(; now < path.length(); )
        {
            while(now + 1 < path.length() && path.charAt(now + 1) == '/') now++;
            int end = now + 1;
            while(end < path.length() && path.charAt(end) != '/') end++;
            String temp = path.substring(now, end);
            
            if(temp.equals("/."))
            {
                now = end;
            }
            else if(temp.equals("/.."))
            {
                if(p.size() > 0) p.remove(p.size() - 1);
            }
            else if(temp.equals("/"))
            {
                now = end;
            }
            else
            {
                p.add(temp);
            }
            now = end;
        }
        String res = String.join("", p);
        return res.equals("") ? "/" : res;
    }
}