#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1e6 + 5;
int start, n, k;

int val[maxn];
int	next[maxn];

int main()
{
	while (scanf("%d%d%d", &start, &n, &k) != EOF)
	{
		memset(next, -1, sizeof(next));
		int non = 1000000, sk = 1000001, lk = 1000002, res = 1000003;
		next[non] = -1, next[sk] = -1, next[lk] = -1;   //1000000: non-negative, 1000001: 0~k, 1000002: k
		int temp;
		while (n--)
		{
			scanf("%d", &temp);
			scanf("%d%d", &val[temp], &next[temp]);
		}

		int now = start;
		while (now != -1)
		{
			temp = next[now];
			if (val[now] < 0)
			{
				next[non] = now;
				next[now] = -1;
				non = now;
			}
			else if (val[now] >= 0 && val[now] <= k)
			{
				next[sk] = now;
				next[now] = -1;
				sk = now;
			}
			else
			{
				next[lk] = now;
				next[now] = -1;
				lk = now;
			}
			now = temp;
		}

		next[sk] = next[1000002];
		next[non] = next[1000001];
		
		now = next[1000000];
		while (now != -1)
		{
			temp = next[now];
			temp != -1 ? printf("%05d %d %05d\n", now, val[now], temp): printf("%05d %d -1\n", now, val[now]);
			now = temp;
		}
	}
    return 0;
}