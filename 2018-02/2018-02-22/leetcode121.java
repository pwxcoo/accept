/**
 * date: 2018-02-22
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    dp
 */

class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        for(int i = 1; i < prices.length; i++)
        {
            if(prices[i] > prices[i - 1]) 
            {
                res = Math.max(res, prices[i] - prices[i - 1]);
                prices[i] = prices[i - 1];
            }
        }
        return res;
    }
}