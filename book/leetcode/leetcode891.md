## Intuition

计算所有的子序列宽度的总和，宽度表示 `max(array) - min(array)`。

1. 先排序。
2. 求出每个元素作为左边界的次数，作为右边界的次数。

作为左边界的话，次数就是 $$2^{i}$$，右边界的话，次数就是 $$2^{n - 1 - i}$$。

----

这个次数的推算就是 n 个元素，有多少种子序列。一个元素是 $$2^{1}$$，两个元素是 $$2^{2}$$，可以根据 dp 来推出，每次选择一个选择或者不选。

- `dp[n] = dp[n - 1] * 2`
- `dp[0] = 1`

其实根据概率论来算也可以，每次选择 m 个元素，有 $$C_{n}^{m}$$ 种组合，这样结果就是

$$
\sum_{i=0}^{n}C_{n}^{i}
$$

最后发现

$$
\sum_{i=0}^{n}C_{n}^{i} = 2^{n}
$$

怎么推出这个的呢？

根据二项式定理 (binomial theorem) ：

$$
\sum_{k=0}^n \binom{n}{k} x^k y^{n-k}=(x+y)^n
$$

当 `x = 1, y = 1` 时，就推出来了。


## Solution

```cpp
/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 *
 * https://leetcode.com/problems/sum-of-subsequence-widths/description/
 *
 * algorithms
 * Hard (28.17%)
 * Total Accepted:    4.2K
 * Total Submissions: 14.7K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array of integers A, consider all non-empty subsequences of A.
 *
 * For any sequence S, let the width of S be the difference between the maximum
 * and minimum element of S.
 *
 * Return the sum of the widths of all subsequences of A. 
 *
 * As the answer may be very large, return the answer modulo 10^9 + 7.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [2,1,3]
 * Output: 6
 * Explanation:
 * Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
 * The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
 * The sum of these widths is 6.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= 20000
 *
 *
 *
 */
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());

        int n = A.size();
        long long res = 0;
        int MOD = 1e9 + 7;

        vector<long long> x(n, 1);
        x[0] = 1;
        for (int i = 1; i < n; i++) {
            x[i] = (x[i - 1] * 2) % MOD;
        }

        for (int i = 0; i < n; i++) {
            res = (res + (x[i] - x[n - 1 - i]) * A[i]) % MOD;
        }

        return res;
    }
};


```