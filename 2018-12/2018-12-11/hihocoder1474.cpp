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
char mat[505][505];
int visit[505][505];

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void construct(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = 2;

    int left = y, right = y, up = x, down = x;
    while (!q.empty()) {
        auto t = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = t.first  + dir[i][0];
            int ny = t.second + dir[i][1];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m || mat[nx][ny] != '1' || visit[nx][ny]) continue;
            visit[nx][ny] = 2;
            q.push({nx, ny});

            left = min(left, ny); right = max(right, ny); up = min(up, nx); down = max(down, nx);
        }
    }

    printf("%d %d\n", down - up + 1, right - left + 1);
    for (int i = up; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            if (visit[i][j] == 2) {
                printf("1");
                visit[i][j] = 1;
            } else printf("0");
        }
        printf("\n");
    }
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", mat[i] + 1);
    }

    for (int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++) {
            if (mat[i][j] == '1' && !visit[i][j]) {
                construct(i, j);
            }
        }

    return 0;
}