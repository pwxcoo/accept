class Solution {
public:
    vector<vector<int>> res;
    void find(int k, int n, int now, vector<int> cur) {
        if (k == 0) {
            if (!n)
                res.push_back(cur); 
            return;
        }
        
        for (int i = now; i <= 9 && n - i >= 0; i++) {
            cur.push_back(i);
            find(k - 1, n - i, i + 1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> used(10, false);
        vector<int> cur;
        find(k, n, 1, cur);
        return res;
    }
};