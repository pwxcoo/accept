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

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

char pa[10005];
char str[1000005];
int N;

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    scanf("%d", &N);
    while (N--) {
        scanf("%s %s", pa, str);
        int next[10005] = {-1};
        int i = 0, j = -1, len = strlen(pa);

        while (i < len) {
            if (j == -1 || pa[i] == pa[j]) next[++i] = ++j;
            else j = next[j];
        }

        int ans = 0, len1 = strlen(str);
        i = j = 0;
        while (i < len1) {
            if (j == -1 || str[i] == pa[j]) ++i, ++j;
            else j = next[j];
            if (j == len) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}