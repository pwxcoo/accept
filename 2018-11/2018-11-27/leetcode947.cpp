class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        cnt = 0; f.clear();
        
        for (auto stone: stones) {
            uni(stone[0], ~stone[1]);
        }
        return (int)stones.size() - cnt;
    }
    
    unordered_map<int, int> f;
    int cnt;
    
    int find(int x) {
        if (!f.count(x)) f[x] = x, cnt++;
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    
    void uni(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx != yy) f[xx] = yy, cnt--;
    }
};