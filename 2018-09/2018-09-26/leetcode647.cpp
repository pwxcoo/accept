class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        vector<char> ss;
        ss.push_back('$');
        ss.push_back('#');
        for (auto c: s)
        {
            ss.push_back(c);
            ss.push_back('#');
        }
        ss.push_back('@');
        
        int id = 0, mx = 0;
        vector<int> p(2*len + 3);
        for (int i = 1; i < ss.size() - 1; i++)
        {
            if (mx > i)
            {
                p[i] = min(p[2*id - i], mx - i);
            }
            while (ss[i - p[i] - 1] == ss[i + p[i] + 1])
            {
                p[i]++;
            }
            if (p[i] + i > mx)
            {
                id = i;
                mx = p[i] + i;
            }
        }
        int res = 0;
        for (auto pp: p)
            res += (pp + 1) / 2;
        return res;
    }
};