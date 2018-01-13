#include<cstdio>

using namespace std;

int n;
const int MAXN = 5e4 + 5;
int post[MAXN], pre[MAXN], in[MAXN];

void build(int preleft, int inleft, int postleft, int len)
{
	if (len <= 0) return;
	int cut = 0;
	for (; cut < len; cut++)
	{
		if (in[inleft + cut] == pre[preleft]) break;
	}
	build(preleft + 1, inleft, postleft, cut);
	build(preleft + 1 + cut, inleft + cut + 1, postleft + cut, len - cut - 1);
	post[postleft + len - 1] = pre[preleft];
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{

		for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++) scanf("%d", &in[i]);
		build(0, 0, 0, n);
		printf("%d\n", post[0]);
	}
    return 0;
}