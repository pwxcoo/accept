## KMP 算法

KMP 是一个时间复杂度 $$O(n+m)$$ 的字符串匹配算法。

其中 `next[]` 数组的建立最重要，`next[i]` 表示第 i 个字符串要是匹配失败了，说明前面 `0 - (i-1)` 是成功的，找到上一个前后缀匹配的字符，然后移动过去，`next[i]` 就是告诉你，第 i 个失败了，你应该回到前面哪里重新匹配。

后面的事情就很机械了。

## 扩展

- `next[]` 数组表示前后缀的匹配，可以求最小循环节 `len - next[len]`。
- `next[]` 数组因为首尾匹配的特性，在某些回文处理中有作用。（比如往前面加若干字符构成回文，就是反转字符串为 r，求 `s+'#'+r` 的 `next[]` 数组。
- `next[]` 可以向前一直遍历，找重复出现的字符串。
- `next[]` 可以查看当前 `prefix` 前面有多少的 `period`。

## 简单的例子

### hdu1711

寻找 a 中是否存在 b。

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

int a[1000005];
int b[10005];
int ne[10005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= M; i++) scanf("%d", &b[i]);

        int x = 0, y = 1;
        for (; y <= M;)
            if (x == 0 || b[y] == b[x]) ne[++y] = ++x;
            else x = ne[x];
        for (int i = 1; i <= M; i++) cout << ne[i] << " ";
        x = 1, y = 1;
        for (; y <= N;) {
            if (x == 0 || a[y] == b[x]) x++, y++;
            else x = ne[x];

            if (x > M) break;
        }
        if (x > M) cout << y - x + 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}
```

### hdu1686

寻找 T 中有多少个 W。找到一个后就 `j = nxt[j]` 重置一下就好了。

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

char W[10005];
char T[1000005];
int nxt[10005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int TT;
    cin >> TT;
    while (TT--) {
        scanf("%s%s", W, T);

        nxt[0] = -1;
        int i = 0, j = -1, lenw = strlen(W);
        while (i < lenw) {
            if (j == -1 || W[j] == W[i]) nxt[++i] = ++j;
            else j = nxt[j];
        }

		i = 0, j = 0;
        int lent = strlen(T);
		int res = 0;
		while (i < lent) {
			if (j == -1 || W[j] == T[i]) i++, j++;
			else j = nxt[j];

			if (j == lenw) {
				res++;
				j = nxt[j];
			}
		}

		cout << res << endl;
    }

    return 0;
}
```

### leetcode214

给 s 前面添加多少个字符就能组成回文。就是看 s 前缀的最长回文是多少，后面的非回文长度就是答案。

构造 `reverse(s) + '#' + s`，然后求 `next[]` 就好了。

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        
        vector<int> next((int)t.size(), 0);
        for (int i = 1; i < (int)t.size(); i++) {
            int pre = next[i - 1];
            while (pre > 0 && t[pre] != t[i]) pre = next[pre - 1];
            next[i] = (pre += t[pre] == t[i]);
        }
        return r.substr(0, r.size() - next.back()) + s;
    }
};
```


## References

- [KMP模板以及简单的入门题总结](https://blog.csdn.net/qq_38891827/article/details/80501506)