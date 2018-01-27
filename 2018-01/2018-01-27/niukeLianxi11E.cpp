#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
#define  LL long long

const int MAXN = 100000 + 10;
const int MAXM = 1e6;
const int mod = 1e9 + 7;
const LL inf = 0x3f3f3f3f3f3f3f;

struct Node {
	LL x, y;
}Point[MAXN], Q[MAXN];
bool cmpx(Node a, Node b) { return a.x<b.x; }
bool cmpy(Node a, Node b) { return a.y<b.y; }
LL sqr(LL a) { return a * a; }
LL GetDis(Node a, Node b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }
LL DIV(int le, int ri) {
	LL ret = inf;
	if (le == ri) return ret;
	if (le + 1 == ri) return GetDis(Point[le], Point[ri]);
	int mid = (le + ri) >> 1;
	LL d1 = DIV(le, mid);
	LL d2 = DIV(mid + 1, ri);
	ret = min(d1, d2);
	double d = sqrt((double)ret);
	int k = 0;
	for (int i = mid; i >= le; i--) {
		if (Point[mid].x - Point[i].x>(LL)d) break;
		Q[++k] = Point[i];
	}
	for (int i = mid + 1; i <= ri; i++) {
		if (Point[i].x - Point[mid].x>(LL)d) break;
		Q[++k] = Point[i];
	}
	sort(Q + 1, Q + 1 + k, cmpy);
	for (int i = 1; i < k; i++) {
		for (int j = i + 1; j <= k && Q[j].y - Q[i].y <= (LL)d; j++)
			ret = min(ret, GetDis(Q[j], Q[i]));
	}
	return ret;
}
int a[MAXN];
int main() {
	int n; scanf("%d", &n);
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		Point[i].x = i;
		Point[i].y = sum;
	}
	sort(Point + 1, Point + 1 + n, cmpx);
	printf("%lld\n", DIV(1, n));
	return 0;
}
