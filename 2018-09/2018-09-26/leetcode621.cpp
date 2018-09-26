class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        
        vector<int> cnt(26, 0);
        int mx = 0, same = 0;
        for (auto c: tasks)
        {
            if (++cnt[c - 'A'] > mx)
            {
                mx = cnt[c - 'A'];
                same = 1;
            }
            else if (cnt[c - 'A'] == mx)
            {
                same++;
            }
                
        }
        return max(sz, (n + 1) * (mx - 1) + same);
    }
};