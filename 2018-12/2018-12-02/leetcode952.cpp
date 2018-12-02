class Solution {
public:
    int fa[100005];
    int cnt[100005];
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void uni(int x, int y) {
        int xx = find(x);
        int yy = find(y);
        if (xx == yy) return;
        fa[xx] = yy;
        cnt[yy] += cnt[xx];
    }
    int largestComponentSize(vector<int>& A) {
        int mark[100005] = {0}, used[100005] = {0};
        for (auto a: A) {
            mark[a] = 1;
            fa[a] = a;
            cnt[a] = 1;
        }
        
        for (int i = 2; i <= 100000; i++) {
            if (!used[i]) {
                int last = -1;
                for (int j = i; j <= 100000; j += i) {
                    used[j] = 1;
                    if (mark[j]) {
                        if (last != -1) uni(last, j);
                        last = j;
                    }
                }
            }
        }
        
        int res = 0;
        for (auto a: A) res = max(res, cnt[a]);
        return res;
    }
};