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

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        if (s[0] != s[i])
        {
            cout << "YES\n" << s[0] << s[i] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
