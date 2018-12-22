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

int a[105];

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    sort(a, a+n);
    int res = 0;
    for (int i = 1; i < n; i += 2) {
        res += a[i] - a[i - 1];
    }
    cout << res << endl;

    return 0;
}
