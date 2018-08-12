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
#define FFT(t,T) for(int t = 1 ; t <= T; t++)
 
typedef long long ll;
const int INF = 0x7fffffff;
const int MAXN = 5e4 + 5;

int T, n;
int camp[MAXN];
char op[6];
int sum[MAXN << 2];

void build(int i, int l, int r)
{
    if (l == r)
    {
        scanf("%d", &sum[i]);
        return;
    }

    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);

    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

int query(int ql, int qr, int i, int l, int r)
{
    if (ql <= l && qr >= r)
        return sum[i];

    int m = (l + r) >> 1;
    int ans = 0;

    if (ql <= m)
        ans += query(ql, qr, i << 1, l, m);
    if (qr > m)
        ans += query(ql, qr, i << 1 | 1, m + 1, r);

    return ans;
}

void update(int id, int val, int i, int l, int r)
{
    if (l == r)
    {
        sum[i] += val;
        return;
    }

    int m = (l + r) >> 1;
    if (id <= m) update(id, val, i << 1, l, m);
    else update(id, val, i << 1 | 1, m + 1, r);

    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}


int main()
{
    //freopen("D:/temp/kickstart/temp/temp.in", "r", stdin);
    scanf("%d", &T);

    FFT(t, T)
    {
        printf("Case %d:\n", t);

        scanf("%d", &n);
        build(1, 1, n);

        int t0, t1;
        while (1)
        {
            scanf("%s", op);
            if (op[0] == 'E') break;
            else if (op[0] == 'Q')
            {
                scanf("%d%d", &t0, &t1);
                printf("%d\n", query(t0, t1, 1, 1, n));
            }
            else if (op[0] == 'A')
            {
                scanf("%d%d", &t0, &t1);
                update(t0, t1, 1, 1, n);
            }
            else if (op[0] == 'S')
            {
                scanf("%d%d", &t0, &t1);
                update(t0, -t1, 1, 1, n);
            }
        }
    }

    return 0;
}
