## Intuition

找到一个字符串里长度为 K 的字典序最小的子序列。

----

第一个字符必定是 [0, n - 1 - K] 区间内最小的字符（如果一样，就是最前面的那个）。

然后化解成子问题，K 不断变小。（RMQ 算法）

## Solution

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

    int k;
    string s;
    cin >> k >> s;

    vector<int> rec[26];
    int sz = s.size();
    for (int i = 0; i < sz; i++) rec[s[i] - 'a'].push_back(i);

    string res = "";
    int p = -1;
    while (k) {
        for (int i = 0; i < 26; i++) {
            auto pp = upper_bound(rec[i].begin(), rec[i].end(), p);
            if (pp == rec[i].end() || sz - *pp < k) continue;
            p = *pp; res += char('a' + i); k--;
            break;
        }
    }

    cout << res << endl;
    return 0;
}
```