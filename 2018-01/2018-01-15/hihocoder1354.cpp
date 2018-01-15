#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int N, M, K, Q;
int b[505], a[505];
int block[505][505];
int x, y, p, q;
int visit[505][505];
int dis[505][505];
const int MAXD = 0x7fffffff;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

struct node
{
	int x, y;
	node(int _x, int _y) : x(_x), y(_y) {};
};

int dijktra()
{
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dis[i][j] = MAXD;
	dis[x][y] = 0;
	queue<node> qu;
	qu.push(node(x, y));
	visit[x][y] = 1;
	while (!qu.empty())
	{
		node t = qu.front(); qu.pop();
		visit[t.x][t.y] = 0;
		int temp[4] = { b[t.x], b[t.x - 1], a[t.y], a[t.y - 1] };

		for (int i = 0; i < 4; i++)
		{
			int nextx = t.x + dir[i][0];
			int nexty = t.y + dir[i][1];
			if (nextx < 1 || nextx > N || nexty < 1 || nexty > M || block[nextx][nexty] == 1) continue;
			if (dis[t.x][t.y] + temp[i] < dis[nextx][nexty])
			{
				dis[nextx][nexty] = dis[t.x][t.y] + temp[i];
				if (!visit[nextx][nexty])
				{
					qu.push(node(nextx, nexty));
					visit[nextx][nexty] = 1;
				}
			}
		}
	}
	return dis[p][q];
}

int main()
{
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(block, 0, sizeof(block));
		for (int i = 1; i < N; i++) scanf("%d", &b[i]);
		for (int i = 1; i < M; i++) scanf("%d", &a[i]);
		scanf("%d", &K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			block[x][y] = 1;
		}
		scanf("%d", &Q);
		while (Q--)
		{
			scanf("%d %d %d %d", &x, &y, &p, &q);
			int res = dijktra();
			res == MAXD ? printf("-1\n") : printf("%d\n", res);
		}
	}

    return 0;
}
