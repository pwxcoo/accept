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

int n;
ll T;
const int MAXN = 2e5 + 5;
int a[MAXN];

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    ll res = 0;
    while (true)
    {
        ll t = 0, m = 0;
        for (int i = 1; i <= n; i++) {
            if (T >= t + a[i]) {
                t += a[i];
                m++;
            }
        }

        if (!m) break;
        res += T / t * m;
        T %= t;
    }

    cout << res << endl;

    return 0;
}