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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int m, n;
int pre[10005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> m >> n;
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        s.insert(pre[i]);
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        if (!s.count(u) && !s.count(v)) {
            printf("ERROR: %d and %d are not found.\n", u, v);
            continue;
        } else if (!s.count(u)) {
            printf("ERROR: %d is not found.\n", u);
            continue;
        } else if (!s.count(v)) {
            printf("ERROR: %d is not found.\n", v);
            continue;
        }

        int a;
        for (int j = 0; j < n; j++) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }

        if (a == u || a == v) {
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        } else {
            printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }


    return 0;
}
