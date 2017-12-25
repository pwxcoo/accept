class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int height = triangle.size();
        int len;
        for(int i = 1; i < height; i++)
        {
            len = triangle[i].size();
            for(int j = 0; j < len; j++)
            {
                if(!j)
                {
                    triangle[i][j] += triangle[i - 1][0];
                }
                else if(j == len - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else
                {
                    triangle[i][j] += min(triangle[i - 1][j - 1],triangle[i - 1][j]);
                }
            }
        }
        int res = triangle[height - 1][0];
        for(int i = 0; i < triangle[height - 1].size(); i++)
        {
            res = min(res, triangle[height - 1][i]);
        }
        return res;
    }
};