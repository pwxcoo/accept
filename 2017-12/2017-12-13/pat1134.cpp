#include<cstdio>
#include<cstring>
#include<unordered_set>
using namespace std;

int n, m, k;
const int maxn = 1e4 + 5;
unordered_set<int> st;

struct edge
{
	int f, to;
	edge(){}
	edge(int x, int y): f(x), to(y) {}
}e[maxn];

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{

		for (int i = 0; i < m; i++) scanf("%d %d", &e[i].f, &e[i].to);

		scanf("%d", &k);
		int nv, temp;
		while (k--)
		{
			st.clear();
			scanf("%d", &nv);
			while (nv--)
			{
				scanf("%d", &temp);
				st.insert(temp);
			}

			bool flag = true;
			for (int i = 0; i < m; i++)
			{
				if (st.find(e[i].f) == st.end() && st.find(e[i].to) == st.end())
				{
					flag = false;
					break;
				}
			}
			flag ? printf("Yes\n") : printf("No\n");
		}
	}

    return 0;
}