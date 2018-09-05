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

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int n;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        int dp[250005] = {0}, f[5005] = {0};
        int cnt = 0, sum = 0;
        int v, m;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &v, &m);
            while(m--)
            {
                sum += v;
                f[++cnt] = v;
            }
        }

        int half = sum / 2;
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = half; j >= f[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - f[i]] + f[i]);
            }
        }
        cout << sum - dp[half] << " " << dp[half] << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}