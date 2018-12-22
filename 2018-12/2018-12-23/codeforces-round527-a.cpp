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

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    int T;
    cin >> T;

    int n, k;
    while (T--) {
        cin >> n >> k;

        string part = "";
        for (int i = 0; i < k; i++) {
            part += (char)('a' + i);
        }

        string res = "";
        for (int i = 0; i < n / k; i++) {
            res += part;
        }

        for (int i = 0; i < n % k; i++) {
            res += (char)('a' + i);
        }
        cout << res << endl;
    }

    return 0;
}
