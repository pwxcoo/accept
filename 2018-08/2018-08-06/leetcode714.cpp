class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len == 0) return 0;
        
        int cash = 0;   // the maximum profit if have no stock
        int hold = -prices[0];  // the maximum profit if have one stock
        for (int i = 1; i < len; i++)
        {
            cash = max(cash, prices[i] + hold - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};