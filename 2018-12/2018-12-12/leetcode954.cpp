class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> m;
        for (auto a: A) m[a]++;

        for (auto mm: m) {
            if (mm.second <= 0) continue;
            if (mm.first < 0) {
                if (m[mm.first / 2] < mm.second) return false;
                m[mm.first / 2] -= mm.second;
            } else {
                if (m[mm.first * 2] < mm.second) return false;
                m[mm.first * 2] -= mm.second;
            }
        }
        return true;
    }
};