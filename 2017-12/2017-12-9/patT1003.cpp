#include<cstdio>
#include<queue>
#include<unordered_map>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
//最大网络流 Dinic

unordered_map<string, int> M;
char x[4], y[4];
int n, tot;

struct MaxFlow
{
	const static int maxp = 1e5 + 10;
	const static int INF = 0x7fffffff;
	struct Edges
	{
		int from, to, cap, flow;
		Edges(int _f, int _t, int _c, int _flow): from(_f), to(_t), cap(_c), flow(_flow) {}
	};
	vector<Edges> edge;
	vector<int> G[maxp];
	bool vis[maxp];
	int dis[maxp];
	int cur[maxp];
	int s, d;		//源点，汇点

	void init(int x)
	{
		edge.clear();
		for (int i = 0; i <= x; i++)
			G[i].clear();
	}

	void addEdge(int from, int to, int cap)
	{
		edge.push_back(Edges(from, to, cap, 0));
		edge.push_back(Edges(to, from, 0, 0));
		int m = edge.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool bfs()
	{
		memset(vis, 0, sizeof(vis));
		queue<int> q;	q.push(s);     vis[s] = 1; 
		dis[s] = 0;
		while (!q.empty())
		{
			int x = q.front();   q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edges& e = edge[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{
					vis[e.to] = 1;
					dis[e.to] = dis[x] + 1;
					q.push(e.to);
				}
			}
		}
		return vis[d];
	}

	int dfs(int now, int low)
	{
		if (now == d || low == 0) return low;
		int flow = 0, f;
		for (int &i = cur[now]; i < G[now].size(); i++)
		{
			Edges& e = edge[G[now][i]];
			if (dis[e.to] == dis[now] + 1 && (f = dfs(e.to, min(low, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edge[G[now][i] ^ 1].flow -= f;
				flow += f;
				low -= f;
				if (!low) break;
			}
		}
		return flow;
	}

	int dinic(int s, int d)
	{
		this->s = s; this->d = d;
		int flow = 0;
		while (bfs())
		{
			memset(cur, 0, sizeof(cur));
			flow += dfs(s, INF);
		}
		return flow;
	}


}solve;

int main()
{
	while (scanf("%s%s%d", x, y, &n) != EOF)
	{
		M[x] = 1; M[y] = 2; tot = 3;
		int z;
		solve.init(n * 2 + 2);
		while (n--)
		{
			scanf("%s%s%d", x, y, &z);
			if (!M[x]) M[x] = tot++;
			if (!M[y]) M[y] = tot++;
			solve.addEdge(M[x], M[y], z);
		}
		printf("%d\n", solve.dinic(1, 2));
	}
    return 0;
}

