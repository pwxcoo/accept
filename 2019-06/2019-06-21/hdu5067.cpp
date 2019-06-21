#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int n, m;
int mat[55][55];
vector<pair<int, int>> stones;
int dp[1 << 10][10];
int dis[10][10];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    while(scanf("%d %d", &n, &m) != EOF) {
        stones.clear();
        memset(dp, INF, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
                if (mat[i][j]) {
                    stones.push_back({i, j});
                }
            }
        }

        int sz = stones.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                dis[i][j] = abs(stones[i].first - stones[j].first) + abs(stones[i].second - stones[j].second);
            }
        }


        for (int i = 0; i < (1 << sz); i++) {
            for (int j = 0; j < sz; j++) {
                if (!(i & (1 << j))) continue;

                if (i == (1 << j)) dp[i][j] = stones[j].first + stones[j].second;
                else {
                    dp[i][j] = INF;
                    for (int u = 0; u < sz; u++) {
                        if (((1 << u) & i) && u != j) {
                            dp[i][j] = min(dp[i][j], dis[u][j] + dp[i ^ (1 << j)][u]);
                        }
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < sz; i++) {
            ans = min(ans, dp[(1 << sz) - 1][i] + stones[i].first + stones[i].second);
        }
        if (ans == INF) ans = 0;
        printf("%d\n", ans);


    }

    return 0;
}
