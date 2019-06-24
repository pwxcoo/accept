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

int nv, ne;
int m, k;

int mat[201][201];

bool isClique(vector<int>& c) {
    for (int i = 0; i < c.size(); i++) {
        for (int j = i + 1; j < c.size(); j++) {
            if (!mat[c[i]][c[j]]) return false;
        }
    }
    return true;
}

bool isMax(vector<int>& c) {
    unordered_set<int> s;
    for (int i = 0; i < c.size(); i++) s.insert(c[i]);

    for (int i = 1; i <= nv; i++) {
        if (s.count(i)) continue;

        bool flag = true;
        for (int j = 0; j < c.size(); j++) {
            if (!mat[i][c[j]]) {
                flag = false;
                break;
            }
        }

        if (flag) return false;
    }

    return true;
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> nv >> ne;

    int e1, e2;
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &e1, &e2);
        mat[e1][e2] = mat[e2][e1] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;

        vector<int> cli;
        int temp;
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            cli.push_back(temp);
        }

        if (!isClique(cli)) {
            cout << "Not a Clique" << endl;
            continue;
        }

        if (!isMax(cli)) {
            cout << "Not Maximal" << endl;
            continue;
        }

        cout << "Yes" << endl;
    }


    return 0;
}
