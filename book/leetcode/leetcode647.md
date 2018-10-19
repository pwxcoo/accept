## Intuition

**Expanding around center** approach has $$O(n^2)$$ time complexity.

One disadvantage of this algorithm is that when the string is "aaaaaaa", every time there are one left pointer, one right pointer required looking for palindromes from zero on both sides. For example, if at 4th "a", the 3rd "a" has traversed to prove that "aaaaa" is palindrome, and the 4th "a" is the internal character of this "aaaaa", **the 4th "a" and 2nd "a" is symmetrical**. So you can apply the result of the 2nd "a" directly to 4th "a".(So allocate an array for recording results, and dp[i] denotes the radius of the longest palindrome in which the i character is the symmetric character.)

Another thing need paying attention is inserting characters in string. Because "aa" is palindrome, but there is no symmetric characters(as the symmetric axis character),that is, even palindrome have no symmetric characters, so we have to divide the odd and even conditions. **But we can insert a "#" in the middle of each characters**, so that "aa" will be "#a#a#", even palindrome will become odd palindrome.(PS: Adding two different characters that have not yet appeared at beginning of string and end of string can prevent overflow during traversal.)

**A simple example is that "aba" will become "$#a#b#a#@".**

```python
origin  "aba"
convert "$#a#b#a#@"
dp      [001030100]
result  sum([(i + 1) // 2 for i in dp]) 
# Because additional characters are added, 
# the palindrome length is twice as much as origin string,
# so the actual number should be divided by 2.
```

This is the **Manacher Algorithm**, which reduces the time complexity to $$O(n)$$, and increase the space complexity to $$O(n)$$, which is take time for space.

## Solution

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        string ss = "$";
        for (auto c: s)
        {
            ss += "#";
            ss += c;
        }
        ss += "#@";
        
        int res = 0;
        vector<int> dp(2 * n + 3, 0);
        int mid = 0, right = 0;
        for (int i = 1; i < 2 * n + 3; i++)
        {
            if (i < right) 
                dp[i] = min(dp[2 * mid - i], right - i);
            while (ss[i + dp[i] + 1] == ss[i - dp[i] - 1]) 
                dp[i]++;
            if (i + dp[i] > right)
            {
                mid = i;
                right = i + dp[i];
            }
            res += (dp[i] + 1) / 2;
        }
        
        return res;
    }
};
```