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
const int MAXN = 1000010;

int n, Q;
int ans_x, ans_y;
int c[MAXN >> 1];

struct node
{
    int r, l;
    int maxx, minn;
}t[MAXN << 2];

void build(int l, int r, int n)
{
    t[n].l = l;
    t[n].r = r;
    t[n].maxx = 0;
    t[n].minn = MAXN;
    if (l == r)
    {
        t[n].maxx = t[n].minn = c[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, n << 1);
    build(mid + 1, r, (n << 1) | 1);
    t[n].maxx = max(t[n << 1].maxx, t[n << 1 | 1].maxx);
    t[n].minn = min(t[n << 1].minn, t[n << 1 | 1].minn);
}

void query(int l, int r, int n)
{
    if (t[n].l == l && t[n].r == r)
    {
        ans_x = max(ans_x, t[n].maxx);
        ans_y = min(ans_y, t[n].minn);
        return;
    }

    int mid = (t[n].l + t[n].r) >> 1;
    if (r <= mid)
        query(l, r, n << 1);
    else if (l > mid)
        query(l, r, n << 1 | 1);
    else
    {
        query(l, mid, n << 1);
        query(mid + 1, r, n << 1 | 1);
    }

}

int main()
{
    scanf("%d %d", &n, &Q);

    FF1(i, n) 
        scanf("%d", &c[i]);
    build(1, n, 1);

    int x, y;
    while (Q--)
    {
        scanf("%d%d", &x, &y);
        ans_x = 0;
        ans_y = MAXN;
        query(x, y, 1);
        printf("%d\n", ans_x - ans_y);
    }

    return 0;
}
