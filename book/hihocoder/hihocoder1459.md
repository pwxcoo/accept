## Intuition

一串只包含小写字符的字符串，用 k 次交换，能得到最长的连续相同字符字串是多长？

----

因为只包含小写字符，所以分成 26 中情况讨论。

区间 [l, r] 内能否经过 k 次交换使 [l, r] 全变成某个字符，说明 [l, r] 是可行的。证明 [l, r] 可行两个充分必要条件。

- 整个字符串的某个字符 a，一定要大于等于 [l, r] 的长度
- [l, r] 内非字符 a 的个数要小于等于 k

然后 l，r 用两个指针，滑动窗口来做。

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

    int n = s.length();
    vector<int> tot(26, 0);
    for (int i = 0; i < n; i++) tot[s[i] - 'a']++;

    int res = 0;
    for (int i = 0; i < 26; i++) {
        int left = 0, right = -1;
        int cnt = 0;

        while (right < n) {
            while (right < n && (right - left + 1 - cnt) <= k && tot[i] >= (right - left + 1)) {
                cnt += s[++right] - 'a' == i ? 1 : 0;
            }
            res = max(right - left, res);
            while (left <= right && ((right - left + 1 - cnt) > k || tot[i] < (right - left + 1))) {
                cnt += s[left++] - 'a' == i ? -1 : 0;
            }
        }
    }
    cout << res << endl;

    return 0;
}
```