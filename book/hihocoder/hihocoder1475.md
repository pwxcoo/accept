## Intuition

将数组拆分成若干段，每一段的和不为 0，求多少种拆法。

----

设长度为 i 的 A，被截断后最后一段为 `A[j + 1] .. A[i]`，可以得到长度为 i 的 A 所有的拆法为 `f[i]`。

可以知道 `f[i]` 为之前所有的 `f[]` 的和，但是不包括 `sum(A[j + 1] ... A[i]) == 0` 的 `f[j]`。

这样复杂度为 $$O(n^2)$$。

但是在遍历的时候保存之前为 0 的结果集合，就可以又优化成 $$O(n)$$ 的复杂度，利用前缀和就可以做到了。

**PS: 这里有个很容易忽略的地方，就是每次结果都会 MOD，所以在出现[全部的总和]减去[为零的总和]会出现负数的情况，所以要加上 MOD。**

## Solution

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

const int MOD = 1e9 + 7;
int n;
int A[100005];
ll f;
int sum;
ll s;

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_map<int, ll> h;
    f = s = 1;
    h[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum = sum + A[i];
        f = (s - h[sum] + MOD) % MOD;
        h[sum] = (h[sum] + f) % MOD;
        s = (s + f) % MOD;
    }

    cout << f << endl;

    return 0;
}
```