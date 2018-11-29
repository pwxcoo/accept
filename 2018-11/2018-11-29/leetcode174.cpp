class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        
        vector<int> dp(m + 1, INT_MAX);
        dp[m - 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int pre = min(dp[j], dp[j + 1]);
                dp[j] = pre - dungeon[i][j];
                if (dp[j] < 0) dp[j] = 0;
            }
        }
        return dp[0] + 1;
    }
};