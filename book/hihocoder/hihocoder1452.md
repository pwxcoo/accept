## Intuition

求一组 word 中，是字符 S 的子序列最长的一个。

-----

求是否是子序列的复杂度是 $$O(|S|)$$，然后复杂度就是 $$O(n * |S|)$$。

但是可以建立一个 f[i][j]，表示 S[i] 之后的下个字符 j 的下标。建立 f 需要 $$O(26 * |S|)$$，然后复杂度就是 $$O(\sum w_i)$$

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

char w[10005][100005];
char s[100005];
int f[100005][27];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", w[i]);
    }
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 0; i < 26; i++) {
        f[len][i] = -1;
    }
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            f[i][j] = f[i + 1][j];
        }
        f[i][s[i + 1] - 'a'] = i + 1;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int j = 0, wlen = strlen(w[i]);
        int now = 0;
        for (; j < wlen && now != -1; j++) {
            now = f[now][w[i][j] - 'a'];
        }
        if (j == wlen && now != -1) res = max(res, wlen);
    }
    printf("%d\n", res);

    return 0;
}
```