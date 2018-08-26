class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int len = grid.size();
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        if (len == 0) return 0;
        
        int res = 0;
        for (int i = 0; i < len; i++) 
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0) continue;
                res += 2;
                for (int k = 0; k < 4; k++)
                {
                    int nexti = i + dir[k][0];
                    int nextj = j + dir[k][1];
                    int adj = (nexti < 0 || nexti >= len || nextj < 0 || nextj >= grid[i].size()) ? 0 : grid[nexti][nextj];
                    
                    res += max(0, grid[i][j] - adj);
                }
            }
        }
        return res;
    }
};