## Intuition

一组 `0-9` 的数字，任意组合数组，得到最大的 `3` 的倍数。

----

有一个数学知识很重要。[divisibility rule for 3](https://math.stackexchange.com/questions/341202/how-to-prove-the-divisibility-rule-for-3-casting-out-threes)。

$$
abcd \mod 3 = (a + b + c + d) \mod 3
$$

有了这个知识，可以发现只用算各个位数加起来的和就可以了，**溢出的问题解决了**，同时**数字顺序的问题也解决了**。

剩下的思路就是剔除掉影响结果的数字就可以了。

- 如果 `total % 3 == 0`，直接得到结果
- 如果 `total % 3 == 1`：
    1. 删除 `{1, 4, 7}` 中的一个
    2. 如果没有 `{1, 4, 7}`，那删除 `{2, 5, 8}` 中的两个也是一样的，同样可以让剩下的 `total` 能被 `3` 整除
- 如果 `total % 3 == 2`：
    1. 删除 `{2, 5, 8}` 中的一个
    2. 如果没有 `{2, 5, 8}`，那删除 `{1, 4, 7}` 中的两个也是一样的，同样可以让剩下的 `total` 能被 `3` 整除

计算前用 `bucket sort` 处理一下就好了。

## Solution

```cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> counter = vector<int>(10, 0);

        int total = 0;
        for (const int& d : digits) {
            counter[d]++;
            total += d;
        }

        if (total % 3 == 0) return getResult(counter);
        else if (total % 3 == 1) {
            if (tryRemove(counter, 1, 1)) return getResult(counter);
            if (tryRemove(counter, 4, 1)) return getResult(counter);
            if (tryRemove(counter, 7, 1)) return getResult(counter);

            if (tryRemove(counter, 2, 2)) return getResult(counter);
            if (tryRemove(counter, 5, 2)) return getResult(counter);
            if (tryRemove(counter, 8, 2)) return getResult(counter);
        } else if (total % 3 == 2) {
            if (tryRemove(counter, 2, 1)) return getResult(counter);
            if (tryRemove(counter, 5, 1)) return getResult(counter);
            if (tryRemove(counter, 8, 1)) return getResult(counter);

            if (tryRemove(counter, 1, 2)) return getResult(counter);
            if (tryRemove(counter, 4, 2)) return getResult(counter);
            if (tryRemove(counter, 7, 2)) return getResult(counter);
        }

        return "";
    }

    bool tryRemove(vector<int>& counter, int num, int size) {
        if (counter[num] >= size) {
            counter[num] -= size;
            return true;
        } else {
            return false;
        }
    }

    string getResult(vector<int>& counter) {
        string res = "";
        for (int i = 9; i >= 0; i--) {
            while (counter[i] != 0) {
                res += '0' + i;
                counter[i]--;
            }
        }
        return res.length() > 1 && res[0] == '0' ? "0" : res;
    }
};
```

时间复杂度：$$O(n)$$