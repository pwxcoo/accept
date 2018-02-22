/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    dp。太屌了这个。
 */

class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int pro1 = 0, pro2 = 0;
        
        for(int i : prices)
        {
            pro2 = Math.max(pro2, hold2 + i);
            hold2 = Math.max(hold2, pro1 - i);
            pro1 = Math.max(pro1, hold1 + i);
            hold1 = Math.max(hold1, -i);
        }
        
        return pro2;
    }
}