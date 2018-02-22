/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n^m), S = O(n)
 * describe:    bfs + dfs
 */

class Solution {
    void dfs(List<List<String>> res, Map<String, List<String>> pre, List<String> cur) {
        if(!pre.containsKey(cur.get(0))) 
        {
            res.add(new ArrayList<String>(cur));
            return;
        }
        
        for(String p : pre.get(cur.get(0)))
        {
            cur.add(0, p);
            dfs(res, pre, cur);
            cur.remove(0);
        }
    }
    
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>();
        Map<String, List<String>> pre = new HashMap<>();
        Map<String, Integer> dis = new HashMap<>();
        List<List<String>> res = new ArrayList<>();
        for(String s : wordList)
        {
            words.add(s);
            dis.put(s, Integer.MAX_VALUE);
            // if(s.equals(be))
        }
            
        if(!words.contains(endWord)) return res;
        if(words.contains(beginWord)) words.remove(beginWord);
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        int nowdis = 1;
        while(!q.isEmpty())
        {
            int size = q.size();
            while(size-- > 0)
            {
                String t = q.poll(), temp;
                if(t.equals(endWord))
                {
                    List<String> cur = new ArrayList<String>();
                    cur.add(endWord);
                    dfs(res, pre, cur);
                    return res;
                }
                
                for(int i = 0; i < t.length(); i++)
                {
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp = t.substring(0, i) + ch + t.substring(i + 1);
                        if(words.contains(temp) && dis.get(temp) >= nowdis)
                        {
                            dis.put(temp, nowdis);
                            List<String> now = pre.getOrDefault(temp, new ArrayList<String>());
                            if(dis.get(temp) > nowdis)
                            {                 
                                now.clear();
                                now.add(t);
                                pre.put(temp, now);
                                q.offer(temp);
                            }
                            else 
                            {
                                now.add(t);
                                pre.put(temp, now);
                            }

                        }
                    }
                }
            }
            if(!res.isEmpty()) return res;
            nowdis++;
        }
        return res;
    }
}