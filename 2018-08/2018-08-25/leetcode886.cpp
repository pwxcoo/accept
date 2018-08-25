class Solution {
public:
    bool dfs(vector<vector<int>>& record, unordered_map<int, int>& color, int now, int c)
    {
        if (color.find(now) != color.end())
            return color[now] == c;
        color[now] = c;
        
        for (auto r: record[now])
        {
            if (!dfs(record, color, r, c^1))
                return false;
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> record(N + 1, vector<int>());
        for(auto r: dislikes)
        {
            record[r[0]].push_back(r[1]);
            record[r[1]].push_back(r[0]);
        }
        unordered_map<int, int> color;
        for (int i = 1; i <= N; i++)
        {
            if (color.find(i) == color.end() && !dfs(record, color, i, 0))
                return false;
        }
        return true;
    }
};