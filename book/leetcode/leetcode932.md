## Intuition

用 1 - N 的元素构造一个数组 A，要求

- 对任意 i < j，没有一个 k（i < k < j），使得 A[k] * 2 = A[i] + A[j]

------

- 如果 A[i] 是奇数，A[j] 是偶数，那必成立。
- 如果 A[k] * 2 != A[i] + A[j]
    - 当 A 中元素，全部加上数字 a，仍然成立
    - 当 A 中元素，全部乘上数字 a，仍然成立

所以可以模拟一个这样一个过程，A 为已成立的数组 A，A1 为 `2 * A - 1`，A2 为 `2 * A`。

```
A = [2, 1, 4, 5, 3]
A1 = [3, 1, 7, 9, 5]
A2 = [4, 2, 8, 10, 6]
B = A1 + A2 = [3, 1, 7, 9, 5, 4, 2, 8, 10, 6]
```

## Solution

```cpp
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res(1, 1);
        while (res.size() < N) {
            vector<int> next;
            for (auto r: res) if (2 * r - 1 <= N) next.push_back(2 * r - 1);
            for (auto r: res) if (2 * r <= N) next.push_back(2 * r);
            res = next;
        }
        return res;
    }
};
```