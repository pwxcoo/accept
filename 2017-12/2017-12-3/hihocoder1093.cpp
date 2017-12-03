#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MAX = 1e9;
const int N = 100005;

int n, m, s, t;
int dis[N];
int vis[N];

struct node
{
	int a;
	int b;
	node(int x, int y) : a(x), b(y) {};
};

vector<node> mymap[N];

void spfa()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) dis[i] = MAX;
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		vis[now] = 0;

		for (int i = 0; i < mymap[now].size(); i++)
		{
			int other = mymap[now][i].a;
			int len = mymap[now][i].b;

			if (dis[now] + len < dis[other])
			{
				dis[other] = dis[now] + len;
				if (!vis[other])
				{
					q.push(other);
					vis[other] = 1;
				}
			}
		}
	}

}

int main()
{
	int u_i, v_i, length_i;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u_i, &v_i, &length_i);
		mymap[u_i].push_back(node(v_i, length_i));
		mymap[v_i].push_back(node(u_i, length_i));
	}
	spfa();
	printf("%d\n", dis[t]);
    return 0;
}
