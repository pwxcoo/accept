class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res(1, 1);
        while (res.size() < N) {
            vector<int> next;
            for (auto r: res) if (2 * r - 1 <= N) next.push_back(2 * r - 1);
            for (auto r: res) if (2 * r <= N) next.push_back(2 * r);
            res = next;
        }
        return res;
    }
};