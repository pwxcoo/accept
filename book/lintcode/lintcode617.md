## Intuition

Find maximum average subarray which length should be greater or equal to given length `k`.

- the minimum average is the minimum of array, the maximum average is the maximum of array.
- binary search `mid` between minimum and maximum, if $$sum(subarray) - mid * len(subarray) > 0$$, then $$minimum = mid$$
- how to judge it in binary search?
    - use pre-sum array `sum[]` denotes $$sum(nums[0] - mid, ..., nums[i] - mid)$$
    - `mn` denotes the minimum sum from `0` to `i - k`
    - if `i >= k && sum[i] > mn`, prove that there is $$sum(nums[j] - mid, ..., num[i] - mid) > 0$$, the real average will greater than `mid`.


## Solution

```cpp
class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    bool judge(vector<int>& nums, double res, int k)
    {
        int n = nums.size();
        vector<double> sum(n + 1);
        double mn = 0;
        for (int i = 1; i <= n; i++)
        {
            sum[i] =  sum[i - 1] + (double)nums[i - 1] - res;
            if (i >= k && sum[i] > mn)
            {
                return true;
            }
            if (i >= k)
                mn = min(mn, sum[i + 1 - k]);
        }
        return false;
        
    }
    
    double maxAverage(vector<int> &nums, int k) {
        if (nums.empty()) return 0.0;
        int n = nums.size();
        double mn = nums[0], mx = nums[0];
        for (int i = 1; i < n; i++)
        {
            mn = min(mn, (double)nums[i]);
            mx = max(mx, (double)nums[i]);
        }
        
        double res = mx;
        while (mx - mn > 1e-8)
        {
            res = (mx + mn) / 2.0;
            if (judge(nums, res, k))
                mn = res;
            else
                mx = res;
        }
        return res;
    }
};
```