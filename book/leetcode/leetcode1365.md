## Intuition

一个数字，得到每个数字的这个数组里比他小的元素的个数。

----

排序后，就相当于得到了结果。**特别留意相同的元素的case。**


## Solution

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        auto idx = vector<int>(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](const int& a, const int& b){
            return nums[a] < nums[b];
        });

        vector<int> res(n);
        res[idx[0]] = 0;
        for (int i = 1; i < n; i++) {
            res[idx[i]] = nums[idx[i]] == nums[idx[i - 1]] ? res[idx[i - 1]] : i;
        }
        return res;
    }
};
```

时间复杂度：$$O(nlogn)$$