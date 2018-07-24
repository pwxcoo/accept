#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<unordered_set>
#include<queue>
#include<stack>

using namespace std;

vector<int> find_cycle(int n, vector<unordered_set<int>>& g, vector<int>& degree)
{
    vector<int> dis(n + 1, 0x7fffffff);
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        for (j = 1; j <= n; j++)
        {
            if (degree[j] == 1) break;
        }
        if (j == n + 1) // until only cycle, use dijkstra
        {
            unordered_set<int> cycle;
            for (int u = 1; u <= n; u++)
                if (degree[u] > 1)
                {
                    dis[u] = 0;
                    cycle.insert(u);
                    for (auto node : g[u])
                        g[0].insert(node);  // regard the cycle as one node, using 0 to substitute
                }
                    
            queue<int> q;
            q.push(0);
            dis[0] = 0;
            while (!q.empty())
            {
                int t = q.front(); q.pop();
                for (auto node : g[t])
                {
                    if (dis[node] > dis[t] + 1)
                    {
                        dis[node] = dis[t] + 1;
                        q.push(node);
                    }
                }
            }
            return dis;
        }
        else
        {
            for (auto node : g[j])
            {
                degree[node]--;
                
            }
            degree[j] = 0;
        }
    }

    return dis;
}

int main()
{
    int T, N;
    freopen("D:/temp/kickstart/2018c-a/A-large-practice.in", "r", stdin);
    freopen("D:/temp/kickstart/2018c-a/A-large-practice.out", "w", stdout);

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int x, y;
        cin >> N;
        vector<unordered_set<int>> graph(N + 1);
        vector<int> degree(N + 1, 0);
        for (int j = 1; j <= N; j++)
        {
            cin >> x >> y;
            graph[x].insert(y); degree[x]++;
            graph[y].insert(x); degree[y]++;

        }

        vector<int> res = find_cycle(N, graph, degree);
        
        cout << "Case #" << i << ":";
        for (int j = 1; j <= N; j++)
        {
            cout << " " << res[j];
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}