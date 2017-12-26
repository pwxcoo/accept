class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(!n) return 0;
        int m = obstacleGrid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    if(!i && !j) 
                    {
                        obstacleGrid[i][j] = 1;
                        continue;
                    }
                    obstacleGrid[i][j] = (i > 0 ? obstacleGrid[i - 1][j] : 0) + (j > 0 ? obstacleGrid[i][j - 1] : 0);
                }
                else 
                {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[n - 1][m - 1];
    }
};