#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int cnt = 0;

bool able(vector<int>& st)
{
    int s = st.size();

    int max_one = st[0], sum = 0;
    for(auto s: st)
    {
        sum += s;
        if (s > max_one)
        {
            max_one = s;
        }
    }

    return max_one * 2 < sum;
}

void dfs(int now, vector<vector<int>>& g, vector<bool>& used, vector<int>& st)
{
    if (now >= g.size()) return;
    if (st.size() >= 3)
        if (able(st))
            cnt++;

    for (int i = now; i < g.size(); i++)
    {
        if (used[i]) continue;
        used[i] = true;
        for (int j = i + 1; j < g[i].size(); j++)
        {
            if (used[j] || g[i][j] == 0) continue;
            
            st.push_back(g[i][j]);
            used[j] = true;

            dfs(i + 1, g, used, st);

            used[j] = false;
            st.pop_back();
        }
        used[i] = false;
    }
}

int main()
{
    int T, N;
    freopen("D:/temp/kickstart/2018c/B-large-practice.in", "r", stdin);
    freopen("D:/temp/kickstart/2018c/B-large-practice.out", "w", stdout);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        vector<vector<int>> graph(N + 1, vector<int>(N + 1));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> graph[i][j];
            }
        }
        
        cnt = 0;
        vector<int> st;
        vector<bool> used(N + 1, false);
        dfs(1, graph, used, st);

        cout << "Case #" << t << ":";
        cout << " " << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}