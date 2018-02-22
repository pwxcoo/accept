/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n^m), S = O(n)
 * describe:    bfs
 */

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>();
        for(String s : wordList) 
            words.add(s);
        
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        int res = 1;
        while(!q.isEmpty())
        {
            int size = q.size();
            while(size-- > 0)
            {
                String t = q.poll(), temp;
                if(t.equals(endWord)) return res;
                
                for(int i = 0; i < t.length(); i++)
                {
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp = t.substring(0, i) + ch + t.substring(i + 1);
                        if(words.contains(temp))
                        {
                            q.offer(temp);
                            words.remove(temp);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
    
    
}