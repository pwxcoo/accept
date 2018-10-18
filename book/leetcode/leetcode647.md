```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        
        vector<char> ns;
        ns.push_back('$');
        ns.push_back('#');
        for (int i = 0; i < len; i++)
        {
            ns.push_back(s[i]);
            ns.push_back('#');
        }
        ns.push_back('#');
        ns.push_back('*');
        
        int root = 0, right = 0;
        vector<int> dp(2 * len + 3, 0);
        
        int res = 0;
        for (int i = 0; i < 2 * len + 3; i++) {
            if (i < right) {
                dp[i] = min(dp[2 * root - i], right - i);
            }
            
            while(ns[i - dp[i] - 1] == ns[i + dp[i] + 1])
                dp[i]++;
            
            if (i + dp[i] > right) {
                root = i;
                right = i + dp[i];
            }
            res += (dp[i] + 1) / 2;
        }
        return res;
        
        
    }
};
```