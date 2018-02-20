/**
 * date: 2018-02-20
 * author: pwxcoo
 * complexity: T = O(2^n), S = O(2^n)
 * describe:    位运算
 */


class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        for(int i = 1; i <= n; i++)
        {
            int temp = 1 << (i - 1);
            for(int j = temp - 1; j >= 0; j--)
            {
                res.add(res.get(j) | temp);
            }
        }
        return res;
    }
}