/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n)
 * describe:    杨辉三角
 */

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        rowIndex++;
        for(int i = 1; i <= rowIndex; i++)
        {
            res.add(1);
            int len = res.size();
            for(int j = len - 2; j > 0; j--)
            {
                res.set(j, res.get(j) + res.get(j - 1));
            }
        }
        
        return res;
    }
}