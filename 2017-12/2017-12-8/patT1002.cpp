#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int n;

struct task
{
	int pro, last, dead;
	void get() { scanf("%d %d %d", &pro, &last, &dead); }
	bool operator<(const task& a)const { return dead == a.dead ? last < a.last :dead < a.dead; }
}t[52];

int dp[55][100000];
int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		t[i].get();
		sum += t[i].last;
	}
	sort(t + 1, t + n + 1);

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j < t[i].last)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (j <= t[i].dead)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i].last] + t[i].pro);
			}
			else dp[i][j] = dp[i][j - 1];
			res = max(res, dp[i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}