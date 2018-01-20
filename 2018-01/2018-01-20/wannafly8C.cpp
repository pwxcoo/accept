#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//状态压缩 + dp

double dp[(1 << 6)][185];		//dp[i][j] 表示状态为i，时间为j时的期望
double p[8][185];

int main()
{
	int n, m;

	while (scanf("%d %d", &n, &m) != EOF) {
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lf", &p[i][j]);

		for (int i = 1; i < (1 << n); i++) {
			//遍历状态
			for (int j = 0; j <= m; j++) {
				//遍历该状态下的所有时间
				for (int k = 0; k < n; k++) {
					//遍历状态下，该时间下。 所有的item
					if ((i & (1 << k)) == 0) continue;
					double temp = 0;

					for (int r = 1; r <= j; r++) 
						temp += (1 + dp[i ^ (1 << k)][j - r]) * p[k][r];	//异或运算得到上一个状态
					dp[i][j] = max(dp[i][j], temp);
				}
			}
		}

		printf("%.5f\n", dp[(1 << n) - 1][m]);
	}

    return 0;
}