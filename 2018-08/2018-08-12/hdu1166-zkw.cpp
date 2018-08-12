#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define FF0(i,n) for(int i = 0 ; i < n ; i ++)
#define FF1(i,n) for(int i = 1 ; i <= n ; i ++)

typedef long long ll;
const int INF = 0x7fffffff;
const int MAXN = 1e5 + 5;

int T, n;
char op[6];
int M;
int sum[MAXN << 2];

void build()
{
    for (M = 1; M <= n + 1; M <<= 1);
    for (int i = M + 1; i <= M + n; i++) scanf("%d", &sum[i]);
    for (int i = M - 1; i; i--)
    {
        sum[i] = sum[i << 1] + sum[i << 1 | 1];
    }
}

void add(int a, int x)
{
    sum[a += M] += x;
    for (a >>= 1; a; a >>= 1)
    {
        sum[a] = sum[a << 1] + sum[a << 1 | 1];
    }
}

ll query(int l, int r)
{
    l = l + M - 1, r = r + M + 1;
    ll ans = 0;
    for (; l^r^1; l >>= 1, r >>= 1)
    {
        if (~l & 1) ans += sum[l ^ 1];
        if (r & 1) ans += sum[r ^ 1];
    }
    return ans;
}

int main()
{
    //freopen("D:/temp/kickstart/temp/temp.in", "r", stdin);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case %d:\n", t);
        scanf("%d", &n);

        build();

        int t0, t1;
        while (1)
        {
            scanf("%s", op);
            if (op[0] == 'E') break;
            else if (op[0] == 'Q')
            {
                scanf("%d%d", &t0, &t1);
                printf("%d\n", query(t0, t1));
            }
            else if (op[0] == 'A')
            {
                scanf("%d%d", &t0, &t1);
                add(t0, t1);
            }
            else if (op[0] == 'S')
            {
                scanf("%d%d", &t0, &t1);
                add(t0, -t1);
            }
        }
    }


    return 0;
}