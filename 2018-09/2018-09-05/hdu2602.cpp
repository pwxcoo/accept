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

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n, V;
        cin >> n >> V;
        vector<int> v(n + 1, 0);
        vector<int> w(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &w[i]);
        }

        vector<int> dp(V + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = V; j >= w[i]; j--)
            {
                if (dp[j] < dp[j - w[i]] + v[i])
                {
                    dp[j] = dp[j - w[i]] + v[i];
                }
            }
        }

        cout << dp[V] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}