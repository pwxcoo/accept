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
        int n, V, K;
        cin >> n >> V >> K;
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

        vector<vector<int>> dp(V + 1, vector<int>(K + 1, 0));
        vector<int> sq1(K + 2, 0), sq2(K + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = V; j >= w[i]; j--)
            {
                for (int kk = 1; kk <= K; kk++)
                {
                    sq1[kk] = dp[j][kk];
                    sq2[kk] = dp[j - w[i]][kk] + v[i];
                }
                sq1[K + 1] = sq2[K + 1] = -1;

                int now = 1;
                int p1 = 1, p2 = 1;
                while (now <= K && (sq1[p1] != -1 || sq2[p2] != -1))
                {
                    dp[j][now] = sq1[p1] > sq2[p2] ? sq1[p1++] : sq2[p2++];
                    if (dp[j][now] != dp[j][now - 1])
                        now++;
                }
            }
        }

        cout << dp[V][K] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}