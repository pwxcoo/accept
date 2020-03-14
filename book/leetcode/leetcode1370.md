## Intuition

拿出最小元素，再拿出次最小的元素，直到拿不出来，然后颠倒一下，拿最大的元素，再拿次最大的元素，直到拿不出来。

循环上述步骤直到拿完元素。

----

计数排序。


## Solution

```cpp
class Solution {
public:
    string sortString(string s) {
        vector<int> m(26, 0);
        for (const auto& c: s) {
            m[c - 'a']++;
        }

        int len = s.length();
        string res = "";
        while (res.length() < len) {
            for (int i = 0; i < 26; i++) {
                if (m[i] > 0) {
                    m[i]--;
                    res += 'a' + i;
                }
            }

            for (int i = 25; i >= 0; i--) {
                if (m[i] > 0) {
                    m[i]--;
                    res += 'a' + i;
                }
            }
        }

        return res;
    }
};
```

时间复杂度：$$O(n)$$