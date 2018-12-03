#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

char W[10005];
char T[1000005];
int nxt[10005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int TT;
    cin >> TT;
    while (TT--) {
        scanf("%s%s", W, T);

        nxt[0] = -1;
        int i = 0, j = -1, lenw = strlen(W);
        while (i < lenw) {
            if (j == -1 || W[j] == W[i]) nxt[++i] = ++j;
            else j = nxt[j];
        }

		i = 0, j = 0;
        int lent = strlen(T);
		int res = 0;
		while (i < lent) {
			if (j == -1 || W[j] == T[i]) i++, j++;
			else j = nxt[j];

			if (j == lenw) {
				res++;
				j = nxt[j];
			}
		}

		cout << res << endl;
    }

    return 0;
}