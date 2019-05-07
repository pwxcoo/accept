class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    pair<int, int> gradient(vector<int>& p1, vector<int>& p2) {
        int x = p2[0] - p1[0];
        int y = p2[1] - p1[1];

        int g = gcd(x, y);
        return g == 0 ? make_pair(x, y) : make_pair(x / g, y / g);
    }

    bool isBoomerang(vector<vector<int>>& points) {
        auto g1 = gradient(points[0], points[1]);
        auto g2 = gradient(points[1], points[2]);

        auto same = make_pair(0, 0);
        if (g1 == same || g2 == same) return false;

        return g1 != g2;
    }
};