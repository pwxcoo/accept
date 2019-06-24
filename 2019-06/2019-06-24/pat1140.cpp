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

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    string s;
    int n;
    cin >> s >> n;

    for (int i = 1; i < n; i++) {
        string t;
        for (int j = 0; j < s.length(); ) {
            int cnt = 1;
            while (j + cnt < s.length() && s[j + cnt] == s[j]) cnt++;

            t += s[j] + to_string(cnt);
            j += cnt;
        }
        s = t;
    }

    cout << s << endl;

    return 0;
}
