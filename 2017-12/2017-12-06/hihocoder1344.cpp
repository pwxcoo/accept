#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
// 80 tle: 最短路+dp+状态压缩。最后貌似在卡常数。


const int MAX = 1e9 + 1;
const int N = 10005;
int n, m, qsum;
int dis[21][N];
struct node
{
	int to;
	int spend;
	node(int x, int y) : to(x), spend(y) {};
};
vector<node> path[N];
struct task
{
	int l;
	int s;
	int e;
	int t;
	int c;
	task(int now, int x, int y, int z, int u) : l(now), s(x), e(y), t(z), c(u) {};
};
vector<task> jobs;

struct state
{
	int completed;
	int pos;
	int money;
	state(int x, int y, int z) : completed(x), pos(y), money(z) {};
};

void spfa()
{
	int vis[N];
	for (int i = 0; i < jobs.size(); i++)
	{
		memset(vis, 0, sizeof(vis));
		//memset(dis[i], MAX, sizeof(dis[i]));
		fill(dis[i], dis[i] + N, MAX);
		queue<int> q;
		q.push(jobs[i].l);
		vis[jobs[i].l] = 1;
		dis[i][jobs[i].l] = 0;
		while (!q.empty())
		{
			int now = q.front(); q.pop();
			vis[now] = 0;

			for (int j = 0; j < path[now].size(); j++)
			{
				if (dis[i][now] + path[now][j].spend < dis[i][path[now][j].to])
				{
					dis[i][path[now][j].to] = dis[i][now] + path[now][j].spend;
					if (vis[path[now][j].to] == 0)
					{
						vis[path[now][j].to] = 1;
						q.push(path[now][j].to);
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &qsum);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		path[u].push_back(node(v, w));
		path[v].push_back(node(u, w));
	}
	int l, s, e, t, c;
	jobs.push_back(task(1, 0, 0, 0, 0));
	for (int i = 1; i <= qsum; i++)
	{
		scanf("%d %d %d %d %d", &l, &s, &e, &t, &c);
		jobs.push_back(task(l, s, e, t, c));
	}
	spfa();

	int **f = new int *[1024 * 1024 * 2 + 1];
	for (int i = 0; i < 1024 * 1024 * 2 + 1; i++)
		f[i] = new int[21]();
	//memset(f, 0, sizeof(f));

	queue<state> q;
	q.push(state(1, 0, 0));
	int next_completed, arrived_time;
	int res = 0;
	while (!q.empty())
	{
		state top = q.front(); q.pop();
		//if (f[top.completed][top.pos] == -1) continue;
		//if (f[top.completed][top.pos] != top.time) continue;
		for (int i = 1; i <= qsum; i++)
		{
			if (top.completed & (1 << i)) continue;
			next_completed = top.completed | (1 << i);
			arrived_time = dis[top.pos][jobs[i].l] + f[top.completed][top.pos];
			if (arrived_time > jobs[i].e)
			{
				//f[next_completed][i] = -1;
			}
			else if (arrived_time < jobs[i].s)
			{
				if (f[next_completed][i] == 0 || jobs[i].s + jobs[i].t < f[next_completed][i])
				{
					res = max(res, top.money + jobs[i].c);
					f[next_completed][i] = jobs[i].s + jobs[i].t;
					q.push(state(next_completed, i, top.money + jobs[i].c));
				}
			}
			else
			{
				if (f[next_completed][i] == 0 || arrived_time + jobs[i].t < f[next_completed][i])
				{
					res = max(res, top.money + jobs[i].c);
					f[next_completed][i] = arrived_time + jobs[i].t;
					q.push(state(next_completed, i, top.money + jobs[i].c));
				}
			}
		}
	}

	//for (int i = 0; i < 1024*2024; i++)
	//	delete[] f[i];
	delete[] f;

	printf("%d\n", res);



	return 0;
}

