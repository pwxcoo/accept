class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < m; jj++) {
                if (A[ii][jj] == 1) {
                    queue<pair<int, int>> q;
                    A[ii][jj] = 2; q.push({ii, jj});
                    
                    
                    queue<pair<int, int>> qq;
                    
                    while (!q.empty()) {
                        auto t = q.front(); q.pop();
                        qq.push(t);
                        
                        for (int i = 0; i < 4; i++) {
                            int nx = t.first + dir[i][0];
                            int ny = t.second + dir[i][1];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] != 1) continue;
                            
                            A[nx][ny] = 2; q.push({nx, ny});
                        }
                    }
                    
                    ////////////////paint finished///////////////////////
                    
                    int round = A[ii][jj];
                    bool found = false;
                    while (!qq.empty()) {
                        auto t = qq.front(); qq.pop();
                        if (round != A[t.first][t.second]) {
                            if (found) return round - 2;
                            else round = A[t.first][t.second];
                        }
                        for (int i = 0; i < 4; i++) {
                            int nx = t.first + dir[i][0];
                            int ny = t.second + dir[i][1];
                            
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (A[nx][ny] == 1) found = true;
                            if (A[nx][ny] == 0 || A[nx][ny] == 1) {
                                A[nx][ny] = round + 1;
                                qq.push({nx, ny});   
                            }
                        }
                        
                    }
                    
                    break;
                }
            }
        }
    }
};