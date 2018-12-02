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

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int T;
    cin >> T;
    int L, F, D;
    while (T--) {
        cin >> L >> F >> D;
        if (gcd(L, D) >= F) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}