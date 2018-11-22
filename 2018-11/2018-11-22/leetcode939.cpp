class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        int res = INT_MAX;
        unordered_map<int, unordered_set<int>> mp;
        for (auto point: points) {
            mp[point[0]].insert(point[1]);
        }
        
        for (auto p1: points) {
            for (auto p2: points) {
                if (p1[0] >= p2[0] || p1[1] >= p2[1]) continue;
                
                if (mp[p1[0]].count(p2[1]) > 0 && mp[p2[0]].count(p1[1]) > 0) {
                    res = min(res, (p2[1] - p1[1]) * (p2[0] - p1[0]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
        
    }
};