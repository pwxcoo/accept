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
int v[1005];
int dp[1005];

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        scanf("%d", &m);

        if (m < 5)
        {
            printf("%d\n", m);
            continue;
        }

        sort(v + 1, v + n + 1);

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = m - 5; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
            }
        }
        cout << m - dp[m - 5] - v[n] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}