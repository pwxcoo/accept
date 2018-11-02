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

const int MOD = 1e9 + 7;
ll dp[31];

void brute(int n)
{
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int k = 1; i - 2 - k >= 0; k++) {
            dp[i] = max(dp[i], dp[i - 2 - k] * (k + 1));
        }
        // cout << i << ": " << dp[i] << endl;
    }
}

ll fastpow(int a, int b)
{
    ll r = 1;
    ll base = a;
    while (b)
    {
        if (b & 1) r = r * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return r;
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << n << endl;
        return 0;
    }

    brute(25);
    if (n <= 25)
    {
        cout << dp[n] << endl;
        return 0;
    }

    int x = 16;
    for (; x <= 25; x++)
    {
        if ((n - x) % 5 == 0) break;
    }

    int k = (n - x) / 5;
    cout << dp[x] * fastpow(4, k) % MOD << endl;

    return 0;
}