## Intuition

字符串，找出最长的字串，要求其中的元音字符（`aeiou`）是偶数。

----

因为只关心 `aeiou` 的奇偶，所以用 5 位就可以表示。用一个 bitmask 来表示当前字串的元音信息。

比如，偶数 `a`，在 bit 上就用一个 0 表示。所以目标字串的 bitmask 应该为 0。

利用前缀的特点，可以让复杂度降到 `O(n)`，对于一个 bitmask，减去前面出现的第一个相同信息的 bitmask 的下标，中间相差的字串就是偶数元音的目标字串。


## Solution

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int len = s.length();
        unordered_map<int, int> m;
        m[0] = -1;

        int bitmask = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            bitmask ^= 1 << (string("aeiou").find(s[i]) + 1) >> 1;
            if (m.find(bitmask) == m.end()) m[bitmask] = i;
            res = max(res, i - m[bitmask]);
        }

        return res;
    }
};
```

时间复杂度：$$O(n)$$