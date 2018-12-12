class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        int n = rods.size();
        
        vector<vector<bool>> dp(22, vector<bool>(10001, false));
        vector<vector<int>>  mx(22, vector<int>(10001, 0));
        dp[0][5000] = true;
        
        int down = 5000 - sum, up = 5000 + sum;
        for (int i = 0; i < n; i++) {
            for (int j = down; j <= up; j++) {
                if (j - rods[i] >= down && dp[i][j - rods[i]]) {
                    dp[i + 1][j] = true;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j - rods[i]] + rods[i]);
                } 
                if (j + rods[i] <= up && dp[i][j + rods[i]]) {
                    dp[i + 1][j] = true;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j + rods[i]]);
                } 
                if (dp[i][j]) {
                    dp[i + 1][j] = true;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j]);  
                }
            }
        }
        return dp[n][5000] ? mx[n][5000] : 0;
    }
};