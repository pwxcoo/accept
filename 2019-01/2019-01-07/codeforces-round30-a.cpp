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

int w, h, u1, d1, u2, d2;

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    cin >> w >> h;
    cin >> u1 >> d1;
    cin >> u2 >> d2;

    if (d1 < d2) {
        swap(d1, d2);
        swap(u1, u2);
    }

    w += (h + d1) * ((double)(h + 1 - d1) / 2);
    w -= u1;
    if (w < 0) w = 0;
    w += (d1 - 1 + d2) * ((double)(d1 - d2) / 2);
    w -= u2;
    if (w < 0) w = 0;
    w += (d2 - 1) * ((double)(d2) / 2);
    cout << w << endl;

    return 0;
}