## Intuition

给出一组木棒的长度，木棒可以合并，组合成两个等长的木棒，求最长的木棒长度。

----

三种状态，拿，A 拿，B 拿。可以用 `0`, `1`, `-1` 代替。化解成背包问题。

- `dp[i][j]`，表示 i 个物品，为 `j - 5000` 长度是否可行（为防止负数，所以 5000 表示 0）
- `mx[i][j]` 表示 i 个物品，为 `j - 5000` 长度时，最大的正数（A 拿的最长为多少)

最后 `mx[n][5000]` 即为结果。

## Solution

```cpp
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
```