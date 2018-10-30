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

int x, y, n;
char s[200005];
int sx[200005], sy[200005];

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    scanf("%d%s%d%d", &n, s + 1, &x, &y);
    if (abs(x) + abs(y) > n || (n + x + y) & 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
		sx[i] = sx[i - 1];
		sy[i] = sy[i - 1];
        if (s[i] == 'R') {
            sx[i]++;
        }
        else if (s[i] == 'L') {
            sx[i]--;
        }
        else if (s[i] == 'U') {
            sy[i]++;
        }
        else {
            sy[i]--;
        }
    }

    int res = 2e5;
    for (int i = 0, j = 0; i <= n; i++) {
        while (j <= n && abs(sx[i] + sx[n] - sx[j] - x) + abs(sy[i] + sy[n] - sy[j] - y) > j - i)
            j++;
        if (j <= n)
			res = min(res, j - i);
		else break;
    }

	cout << res << endl;

    return 0;
}