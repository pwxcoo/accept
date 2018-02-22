/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n^2)
 * describe:    杨辉三角
 */

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 1; i <= numRows; i++)
        {
            List<Integer> temp = new ArrayList<>();
            for(int j = 0; j < i; j++)
            {
                if(j == 0 || j == i - 1) 
                    temp.add(1);
                else
                {
                    temp.add(res.get(i - 2).get(j - 1) + res.get(i - 2).get(j));
                }
            }
            res.add(temp);
        }
        return res;
    }
}