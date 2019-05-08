#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int n, m;
int p[1005];
int d[1005];

int find(int x) {
    return p[x] == x ? x : find(p[x]);
}

void connect(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx == yy) return;
    p[xx] = p[yy];
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);


    while (1) {
        cin >> n; if (!n) break;
        cin >> m;

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            d[i] = 0;
        }

        int t1, t2;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &t1, &t2);
            connect(t1, t2);
            d[t1]++; d[t2]++;
        }
        int cnt = 0;
        int even = true;
        for (int i = 1; i <= n; i++) {
            if (p[i] == i) cnt++;
            if (d[i] & 1) {
                even = false;
                break;
            }
        }
        if (cnt != 1 || !even) {
            cout << "0" << endl;
        } else {
            cout << "1" << endl;
        }
    }

    return 0;
}
