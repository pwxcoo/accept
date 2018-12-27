## Intuition

给定 x 和 taget，求需要最少的 operators(+, -, *, /) 得到 target。

----

一开始想着 bfs 的思路，但是想着想着总感觉很奇怪。

其实是考察对进制的理解，然后用 dp 的思路来做。

**target 就是用 x 进制来表示。**

每一位 `number[i]`，i 表示第几位，即 `x^i` 的单位，`number[0]` 表示 `x^0`。假设这一位是 a，即这一位可以通过 `a * (x^i)` 来得到，或者可以通过 `1 * (x ^ (i + 1)) - (x - a) * (x ^ i)` 得到。

举个例子就是如果 10 进制，6 可以通过 `6 * 10 ^ 0 = 6 * 1` 得到，也可以通过 `1 * (10 ^ 1) - (10 - 6) * (10 ^ 0) = 10 - 4`。

所以某一位只有这两种可能，然后 dp 一下就好了。

值的注意的是，对进制的理解。

- `y /= x` 相当于用 x 进制表示的 y 右移一位。(类比二进制的 `y >> 1 = y / 2`)
- `y % x` 相当于得到 x 进制表示的 y 最低位的大小。（类比二进制的 `y % 2 = y & 1`)


## Solution

```cpp
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = (target % x) * 2, neg = (x - target % x) * 2;
        target /= x;
        
        int k = 1;
        for (; target > 0; target /= x, k++) {
            int cur = target % x;
            int pos2 = min(pos + cur * k, neg + (cur + 1) * k);
            int neg2 = min(pos + (x - cur) * k, neg + (x - cur - 1) * k);
            pos = pos2, neg = neg2;
        }
        
        return min(pos, k + neg) - 1;
    }
};
```