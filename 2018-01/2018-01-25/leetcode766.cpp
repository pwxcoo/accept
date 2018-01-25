class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0; i < row; i++)
        {
            int nowr = i, nowc = 0;
            while(nowr + 1 < row && nowc + 1 < col){
                nowr += 1; nowc += 1;
                if(matrix[i][0] != matrix[nowr][nowc]){
                    return false;
                }
            }    
        }
        
        for(int i = 1; i < col; i++)
        {
            int nowr = 0, nowc = i;
            while(nowr + 1 < row && nowc + 1 < col){
                nowr += 1; nowc += 1;
                if(matrix[0][i] != matrix[nowr][nowc]){
                    return false;
                }
            }    
        }
        
        return true;      
    }
};