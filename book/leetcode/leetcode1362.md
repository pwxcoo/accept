## Intuition

找出一个数两个因子，要求两个因子绝对值最小。

----

从 $$sqrt(num)$$ 开始搜索。

## Solution

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> one = find(num + 1);
        vector<int> two = find(num + 2);

        return one[1] - one[0] < two[1] - two[0] ? one : two;
    }

    vector<int> find(int num) {
        for (int i = sqrt(num); i >= 1; i--) {
            if (num % i == 0) {
                return vector<int>{i, num / i};
            }
        }
        return vector<int>{1, num};
    }
};
```

时间复杂度：$$O(sqrt(n))$$