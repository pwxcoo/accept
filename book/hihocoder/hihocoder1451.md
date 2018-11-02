## Intuition

four operations：

- type 'A'
- Ctrl-A
- Ctrl-C
- Ctrl-V

The maximum number of 'A's you can type into text area with a limited operation number `N`.

-----

第一感觉是 DP，`dp[i] = max(dp[i - 1] + 1, dp[i - 2 - k] * (k + 1))`。

- 一种是加一个 'A'
- 一种是 Ctrl-V 结尾，k 代表最后用了几次 Ctrl-V。（可以发现的是根据贪心算法，Ctrl-V 结尾的话，最后的几次 Ctrl-V 一定是连续的，这样才能使结果最大)

但是数据范围是 `1e9` 了。。DP 是不行的，其实这题就是找规律，打表了前面的结果后：

```
1: 1
2: 2
3: 3
4: 4
5: 5
6: 6
7: 9
8: 12
9: 16
10: 20
11: 27
12: 36
13: 48
14: 64
15: 81
16: 108
17: 144
18: 192
19: 256
20: 324
21: 432
22: 576
23: 768
24: 1024
25: 1296
26: 1728
27: 2304
28: 3072
29: 4096
30: 5184
31: 6912
32: 9216
33: 12288
34: 16384
35: 20736
36: 27648
37: 36864
38: 49152
39: 65536
40: 82944
41: 110592
42: 147456
43: 196608
44: 262144
45: 331776
46: 442368
47: 589824
48: 786432
49: 1048576
50: 1327104
51: 1769472
52: 2359296
53: 3145728
54: 4194304
55: 5308416
56: 7077888
57: 9437184
58: 12582912
59: 16777216
60: 21233664
61: 28311552
62: 37748736
63: 50331648
64: 67108864
65: 84934656
66: 113246208
67: 150994944
68: 201326592
69: 268435456
70: 339738624
71: 452984832
72: 603979776
73: 805306368
74: 1073741824
75: 1358954496
76: 1811939328
77: 2415919104
78: 3221225472
79: 4294967296
80: 5435817984
81: 7247757312
82: 9663676416
83: 12884901888
84: 17179869184
85: 21743271936
86: 28991029248
87: 38654705664
88: 51539607552
89: 68719476736
90: 86973087744
91: 115964116992
92: 154618822656
93: 206158430208
94: 274877906944
95: 347892350976
96: 463856467968
97: 618475290624
98: 824633720832
99: 1099511627776
100: 1391569403904
```

发现当 `n >= 11` 后，`dp[n] = dp[n - 5] * 4`，所以得到

- `dp[n] = dp[x] * 4 ^ k`
- `n = x + 5 * k`

所以只要找到 x 就可以了，遍历前面的结果找到一个 `(n - x) % 5 == 0` 就可以了，因为是对 5 取余，所以只要最多遍历 10 个值就可以找到了。然后对 `4^k` 用快速幂就好了。

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

const int MOD = 1e9 + 7;
ll dp[31];

void brute(int n)
{
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int k = 1; i - 2 - k >= 0; k++) {
            dp[i] = max(dp[i], dp[i - 2 - k] * (k + 1));
        }
        // cout << i << ": " << dp[i] << endl;
    }
}

ll fastpow(int a, int b)
{
    ll r = 1;
    ll base = a;
    while (b)
    {
        if (b & 1) r = r * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return r;
}

int main(int argc, const char *argv[])
{
    // freopen("input.in", "r", stdin);

    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << n << endl;
        return 0;
    }

    brute(25);
    if (n <= 25)
    {
        cout << dp[n] << endl;
        return 0;
    }

    int x = 16;
    for (; x <= 25; x++)
    {
        if ((n - x) % 5 == 0) break;
    }

    int k = (n - x) / 5;
    cout << dp[x] * fastpow(4, k) % MOD << endl;

    return 0;
}
```