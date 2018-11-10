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

    string s;
    cin >> s;

    int len = s.length();
    stack<int> st;
    vector<pair<int, int>> res;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            st.push(i + 1);
        } else {
            if (!st.empty()) {
                res.push_back(make_pair(st.top(), i + 1));
                st.pop();
            }
        }
    }
    sort(res.begin(), res.end());
    for (auto r: res) {
        cout << r.first << " " << r.second << endl;
    }

    return 0;
}