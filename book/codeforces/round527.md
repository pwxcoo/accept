# Problems

## A. Uniform String

### Intuition

尽可能平均。

### Solution

```cpp
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

```

## B. Teams Forming

### Intuition

排序。

### Solution

```cpp
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

```

## C. Prefixes and Suffixes

### Intuition

给定一堆前缀和后缀，找到最长的两个，然后分别为前缀和后缀的两种情况。

### Solution

```cpp
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

int n;
string s[205], backup[205];
string ori;
char res[205];

bool isp(string x) {
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != ori[i]) return false;
    }
    return true;
}

bool iss(string x) {
    int len = x.length();
    for (int i = len - 1; i >= 0; i--) {
        if (x[i] != ori[n - len + i]) return false;
    }
    return true;
}

bool check() {
    for (int i = 0; i < 2 * n - 2; i += 2) {
        if (!(isp(s[i]) && iss(s[i + 1]) || isp(s[i + 1]) && iss(s[i]))) return false;
    }
    return true;
}

void print() {
    vector<int> vis(2 * n, 0);
    for (int i = 0; i < 2 * n - 2; i++) {
        if (isp(backup[i]) && !iss(backup[i])) res[i] = 'P';
        else if (iss(backup[i]) && !isp(backup[i])) res[i] = 'S';
        else if (iss(backup[i]) && isp(backup[i])) {
            if (!vis[backup[i].length()]) {
                res[i] = 'P';
                vis[backup[i].length()] = 1;
            } else res[i] = 'S';
        }
    }
    res[2 * n - 2] = '\0';
    printf("%s\n", res);
}

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < 2 * n - 2; i++) {
        cin >> s[i];
        backup[i] = s[i];
    }
    sort(s, s + 2 * n - 2,
        [](const string a, const string b) -> bool {
            return a.length() < b.length();
        });
    // for (int i = 0; i < 2 * n - 2; i++) {
        // cout << s[i] << " " << backup[i] <<  endl;
    // }
    ori = s[2 * n - 3][0] + s[2 * n - 4];
    if (check()) {
        print();
    } else {
        ori = s[2 * n - 4][0] + s[2 * n - 3];
        print();
    }

    return 0;
}
```

