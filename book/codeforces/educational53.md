# Problems

[Educational Codeforces Round 53 (Rated for Div. 2)](https://codeforces.com/contest/1073)

## A. Diverse Substring

当一个长度为 n 的字符串之中没有字符大于 n/2，证明这是一个 Diverse Substring。

### Intuition

其实只用找到一个长度为 2，两个字符不相同的字串就好了。

### Solution

```cpp
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

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        if (s[0] != s[i])
        {
            cout << "YES\n" << s[0] << s[i] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}

```

## B. Vasya and Books

标号为 1～n 的书被放到栈 a 里，要求按 b 序列的方式取出，求每个操作取多少书。

### Intuition

直接模拟就好了

### Solution

```cpp
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

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> find(n + 1, 0);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (find[b[i]] == 1) {
            cout << "0" << " ";
        }
        else {
            int count = 0;
            while (now < n && !find[b[i]]) {
                count++;
                find[a[now++]] = 1;
            }
            cout << count << " ";
        }
    }
    
    cout << endl;

    return 0;
}

```

## C. Vasya and Robot

一个机器人从 (0, 0) 移动到 (x, y)。求怎么修正原始的移动序列(长度为 n)，使得最后一个修改的下标减去最前一个修改的下标让值最小。

### Intuition

设结果应该为修改 [l, r] 之间的序列，所以要求出 [0, l) + (r, n] 移动序列之后的位置和 (x, y) 之间的“距离”，验证是否能通过修改 r - l + 1 步，让其到 (x, y)。

可以通过 pre-sum 的方式存储状态，存储 x 轴的状态到 sx，存储 y 轴的状态到 sy。

### Solution

```cpp
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

int x, y, n;
char s[200005];
int sx[200005], sy[200005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    scanf("%d%s%d%d", &n, s + 1, &x, &y);
    if (abs(x) + abs(y) > n || (n + x + y) & 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
		sx[i] = sx[i - 1];
		sy[i] = sy[i - 1];
        if (s[i] == 'R') {
            sx[i]++;
        }
        else if (s[i] == 'L') {
            sx[i]--;
        }
        else if (s[i] == 'U') {
            sy[i]++;
        }
        else {
            sy[i]--;
        }
    }

    int res = 2e5;
    for (int i = 0, j = 0; i <= n; i++) {
        while (j <= n && abs(sx[i] + sx[n] - sx[j] - x) + abs(sy[i] + sy[n] - sy[j] - y) > j - i)
            j++;
        if (j <= n)
			res = min(res, j - i);
		else break;
    }

	cout << res << endl;

    return 0;
}
```

## D. Berland Fair

去环形集市买东西，看到可以买就直接付钱去下一个，直到没钱为止。求消费的次数。

### Intuition

求出一次环形逛集市消耗了多少，然后取余减少重复的次数。

### Solution

```cpp
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

int n;
ll T;
const int MAXN = 2e5 + 5;
int a[MAXN];

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    ll res = 0;
    while (true)
    {
        ll t = 0, m = 0;
        for (int i = 1; i <= n; i++) {
            if (T >= t + a[i]) {
                t += a[i];
                m++;
            }
        }

        if (!m) break;
        res += T / t * m;
        T %= t;
    }

    cout << res << endl;

    return 0;
}
```