## Intuition

逐行&逐列非升序的矩阵。计算负数 grid 的个数。

----

和 [《剑指offer》里二维数组中的查找](/book/offer/) 一样。

## Solution

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                res += m - j;
                i--;
            } else {
                j++;
            }
        }
        
        return res;
    }
};
```

时间复杂度：$$O(n+m)$$