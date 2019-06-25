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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n;
int num[100005];

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp >= 1 && temp <= 100000) {
            num[temp] = 1;
        }
    }

    for (int i = 1; i <= 100001; i++) {
        if (num[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }




    return 0;
}
