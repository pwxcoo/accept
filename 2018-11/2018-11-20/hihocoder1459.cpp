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

    int k;
    string s;
    cin >> k >> s;

    int n = s.length();
    vector<int> tot(26, 0);
    for (int i = 0; i < n; i++) tot[s[i] - 'a']++;

    int res = 0;
    for (int i = 0; i < 26; i++) {
        int left = 0, right = -1;
        int cnt = 0;

        while (right < n) {
            while (right < n && (right - left + 1 - cnt) <= k && tot[i] >= (right - left + 1)) {
                cnt += s[++right] - 'a' == i ? 1 : 0;
            }
            res = max(right - left, res);
            while (left <= right && ((right - left + 1 - cnt) > k || tot[i] < (right - left + 1))) {
                cnt += s[left++] - 'a' == i ? -1 : 0;
            }
        }
    }
    cout << res << endl;

    return 0;
}