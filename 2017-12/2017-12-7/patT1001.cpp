#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
int pre[501];
const int INF = 0x7fffffff;


int find(int x)
{
	// `pre[x] = find(pre[x])` 的查询优化。我操了。
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

struct edge
{
	int u;
	int v;
	int cost;
	int status;
	void get() { scanf("%d %d %d %d", &u, &v, &cost, &status); }
	bool operator<(const edge&a)const
	{
		return status == a.status ? cost < a.cost : status > a.status;
	}
};

int add(int x, int y)
{
	int xx = find(x);
	int yy = find(y);
	if (xx == yy) return 1;
	pre[xx] = yy;
	return 0;
}

int main()
{
	//input
	scanf("%d %d", &n, &m);
	edge* e = new edge[m];
	for (int i = 0; i < m; i++)	e[i].get();
	sort(e, e + m);

	int c[501];
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int i = 0; i <= n; i++) pre[i] = i;
		c[i] = 0;
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (e[j].u == i || e[j].v == i) continue;
			if (add(e[j].u, e[j].v)) continue;
			cnt++;
			if (!e[j].status) c[i] += e[j].cost;
		}
		if (cnt < n - 2) c[i] = INF;
		res = max(res, c[i]);
	}

	if (res)
	{
		bool isFirst = true;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == res)
			{
				isFirst ? printf("%d", i) : printf(" %d", i);
				isFirst = false;
			}
		}
		printf("\n");
	}
	else printf("0\n");
	return 0;
}
