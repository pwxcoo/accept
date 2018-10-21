```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int len = s.length();
        
        int start = 0;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            if (m.find(s[i]) == m.end() || m[s[i]] < start)
            {
                m[s[i]] = i;
                res = max(res, i - start + 1);
            }
            else
            {
                start = m[s[i]] + 1;
                m[s[i]] = i;
            }
        }
        return res;
    }
};
```