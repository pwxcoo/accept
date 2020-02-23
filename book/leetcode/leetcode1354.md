## Intuition

把一个 `[1, 1, ..., 1]` 根据一定的规则更新成 target array。

规则：

1. 计算当前 `sum`。
2. 替换一个值让他变成 `sum`
3. 重复步骤 1

----

target 里的最大值一定是被替换的值，该值被替换前的值是 `pre = mx - (sum - mx)`。一直迭代就好。

注意迭代的时候同时还要满足一个条件，替换前的值一定是大于等于 `1` 的。

## Solution

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        long long mx = 0;

        for (int i = 0; i < target.size(); i++) {
            mx = target[i] > target[mx] ? i : mx;
            sum += target[i];
        }
        if (target[mx] <= 1) return sum == target.size();
        if (2 * target[mx] - sum < 1) return false;

        target[mx] = 2 * target[mx] - sum;

        return isPossible(target);
    }
};
```

时间复杂度：不会算

对于这种 `[1, 1000000000]`，test case 是可能 TLE，但是貌似没有这个 test case。暂时没想到别的更好的解法。