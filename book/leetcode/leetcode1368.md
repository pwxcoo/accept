## Intuition

一个矩阵，里面每个元素规定了下一步的方向，可以消耗一个 `cost` 改变方向，求左上角到右下角最小的 `cost`。

----

bfs 的思路。最开始什么都不 `cost`，把所有的能到的点放到队列里，然后遍历队列拿出一个点，改变方向，然后继续把能到的点（且为访问过的）放到队列里。

这个算法的性质可以保证，在队列里的点 `cost` 一定是非递减的。


## Solution

```cpp
class Solution {
private:
    const int M = 100;
    int dir[5][2] = {0, 0, 0, 1, 0, -1, 1, 0, -1, 0};
    int n, m;
    int vis[100][100];
    void findAll(int curi, int curj, int cost, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        while (curi >= 0 && curi < n && curj >= 0 && curj < m && !vis[curi][curj]) {
            q.push(make_pair(curi * 100 + curj, cost));
            vis[curi][curj] = 1;

            int deltaI = dir[grid[curi][curj]][0];
            int deltaJ = dir[grid[curi][curj]][1];
            curi += deltaI;
            curj += deltaJ;
        }
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, sizeof(vis), 0);
        queue<pair<int, int>> q; // first is index, second is cost

        findAll(0, 0, 0, q, grid);

        while (!q.empty()) {
            auto t = q.front(); q.pop();

            int curi = t.first / 100, curj = t.first % 100;
            if (curi == n - 1 && curj == m - 1) return t.second;
            for (int i = 1; i <= 4; i++) {
                if (grid[curi][curj] == i) continue;
                findAll(curi + dir[i][0], curj + dir[i][1], t.second + 1, q, grid);
            }
        }

        throw invalid_argument("bad solution");
    }
};
```

时间复杂度：$$O(n*m)$$