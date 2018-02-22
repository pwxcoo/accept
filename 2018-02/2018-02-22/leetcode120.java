/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    dp
 */

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for(int i = 1; i <= triangle.size(); i++)
        {
            List<Integer> temp = triangle.get(i - 1);
            if(i == 1) continue;
            List<Integer> last = triangle.get(i - 2);
            for(int j = 0; j < temp.size(); j++)
            {
                if(j == 0)
                    temp.set(0, temp.get(0) + last.get(0));
                else if(j == temp.size() - 1)
                    temp.set(j, temp.get(j) + last.get(j - 1));
                else 
                    temp.set(j, temp.get(j) + Math.min(last.get(j - 1), last.get(j)));
            }
        }
        
        int len = triangle.size();
        int res = triangle.get(len - 1).get(0);
        for(int i = 1; i < len; i++)
        {
            res = Math.min(triangle.get(len - 1).get(i), res);
        }
        return res;
    }
}