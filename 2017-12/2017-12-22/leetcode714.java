class Solution {
    public int maxProfit(int[] prices, int fee) {
        int len = prices.length;
        int[] dp = new int[len];
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < len; i++)
        {
            cash = Math.max(cash, hold + prices[i] - fee);
            hold = Math.max(hold, cash - prices[i]);
        }
        return cash;
    }
}