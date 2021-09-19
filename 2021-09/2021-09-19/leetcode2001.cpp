class Solution {
public:
    int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;
        
        for (auto const& r: rectangles) {
            int g = gcd(r[0], r[1]);
            m[make_pair(r[0] / g, r[1] / g)]++;
        }
        
        long long res = 0;
        for (auto const& mm: m) {
            long long cnt = mm.second;
            res += cnt * (cnt - 1) / 2;
        }
        
        return res;
    }
};