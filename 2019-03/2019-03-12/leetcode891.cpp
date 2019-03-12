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

