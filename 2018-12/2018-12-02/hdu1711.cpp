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

int a[1000005];
int b[10005];
int ne[10005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= M; i++) scanf("%d", &b[i]);

        int x = 0, y = 1;
        for (; y <= M;)
            if (x == 0 || b[y] == b[x]) ne[++y] = ++x;
            else x = ne[x];
        for (int i = 1; i <= M; i++) cout << ne[i] << " ";
        x = 1, y = 1;
        for (; y <= N;) {
            if (x == 0 || a[y] == b[x]) x++, y++;
            else x = ne[x];

            if (x > M) break;
        }
        if (x > M) cout << y - x + 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}