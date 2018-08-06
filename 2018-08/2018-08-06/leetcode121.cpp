class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int s = 0, dif = 0;
        for (int i = s + 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[s])
            {
                if (prices[i] - prices[s] > dif)
                    dif = prices[i] - prices[s];
            }
            else
                s = i;
        }
        return dif;
    }
};