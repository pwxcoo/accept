class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        
        vector<int> next((int)t.size(), 0);
        for (int i = 1; i < (int)t.size(); i++) {
            int pre = next[i - 1];
            while (pre > 0 && t[pre] != t[i]) pre = next[pre - 1];
            next[i] = (pre += t[pre] == t[i]);
        }
        return r.substr(0, r.size() - next.back()) + s;
    }
};