## Intuition

步长为 F，台阶长 L，每次走 D。

----

因为无限走下去，位置是有限集，所以必然有循环节。

设起始位置脚后跟到上一个缝隙的长度为 `X`，可以得到 `(X + a * D) % L` 为之后的位置，`a` 为步数，第一次回到起始位置时，`a` 为 `L / gcd(D, L)`。

所以位置集合为 `{X, X+gcd, X+2gcd, ..., X+L-gcd}`，要求最有可能踩到缝隙的结果为 `X+L-gcd`，要保证 `X+L-gcd + F < L`，就能保证成立。

所以 `X` 最好为 0，即 `gcd < F` 成立。


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

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int T;
    cin >> T;
    int L, F, D;
    while (T--) {
        cin >> L >> F >> D;
        if (gcd(L, D) >= F) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
```