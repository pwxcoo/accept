## Intuition

给了左右孩子的指针。判断是不是一个二叉树。

----

我就想到两点：

1. 有且仅有一个 `root`
2. 每个 `node` 的入度小于等于 1


PS: 看了 discuss，test case 不太行，不知道有没有漏的

## Solution

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> fr = vector<int>(n, 0);

        for (const int& c : leftChild) {
            if (c != -1) {
                fr[c]++;
            }
        }
        for (const int& c : rightChild) {
            if (c != -1) {
                fr[c]++;
            }
        }

        int zeroCnt = 0;
        for (int i = 0; i < n; i++) {
            zeroCnt += fr[i] == 0 ? 1 : 0;

            // multiple parent
            if (fr[i] > 1) return false;
        }

        return zeroCnt == 1;
    }
};
```

时间复杂度：$$O(n)$$