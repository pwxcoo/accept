class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> edges(N + 1, vector<int>(N+1, -1));
        for(auto e: times) edges[e[0]][e[1]] = e[2];
        vector<int> dist(N + 1, INT_MAX);
        queue<int> q;
        vector<int> vis(N + 1, 0);
        q.push(K);
        vis[K] = 1;
        dist[K] = 0;
        while(!q.empty())
        {
            int top = q.front(); q.pop();
            vis[top] = 0;
            for(int i = 1; i <= N; i++)
            {
                if(edges[top][i] != -1 && edges[top][i] + dist[top] < dist[i])
                {
                    dist[i] = edges[top][i] + dist[top];
                    if(!vis[i])
                    {
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= N; i++) 
        {
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};