class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        for (int i = 0; i <= 9; i++) {
            res.push_back(i);
        }
        
        for (int i = 2; i <= N; ++i) {
            vector<int> tmp;
            for (int x : res) {
                int y = x % 10;
                if (x > 0 && y + K < 10)
                    tmp.push_back(x * 10 + y + K);
                if (x > 0 && K > 0 && y - K >= 0)
                    tmp.push_back(x * 10 + y - K);
            }
            res = tmp;
        }
        
        return res;
    }
};