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

const int MOD = 1e9 + 7;
int n;
int A[100005];
ll f;
int sum;
ll s;

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_map<int, ll> h;
    f = s = 1;
    h[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum = sum + A[i];
        f = (s - h[sum] + MOD) % MOD;
        h[sum] = (h[sum] + f) % MOD;
        s = (s + f) % MOD;
    }

    cout << f << endl;

    return 0;
}