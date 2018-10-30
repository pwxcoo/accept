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
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> find(n + 1, 0);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (find[b[i]] == 1) {
            cout << "0" << " ";
        }
        else {
            int count = 0;
            while (now < n && !find[b[i]]) {
                count++;
                find[a[now++]] = 1;
            }
            cout << count << " ";
        }
    }
    
    cout << endl;

    return 0;
}
