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

struct record {
    int score[3] = {0, 0, 0};
    int num;

};

int n;
unordered_map<string, record> m;

struct institution {
    string name;
    int tws;
    int ts;
    int rank;
};

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    cin >> n;
    m.clear();

    string id, school;
    int sc;
    for (int i = 0; i < n; i++) {
        cin >> id >> sc >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);

        if (id[0] == 'B') m[school].score[0] += sc;
        else if (id[0] == 'A') m[school].score[1] += sc;
        else if (id[0] == 'T') m[school].score[2] += sc;

        m[school].num++;
    }

    vector<institution> res;
    for (auto const &r : m) {
        res.push_back({
            r.first,
            r.second.score[0] / 1.5 + r.second.score[1] + r.second.score[2] * 1.5,
            r.second.num});
    }

    sort(res.begin(), res.end(), [](const institution & a, const institution & b) -> bool {
        if (a.tws != b.tws) return a.tws > b.tws;
        if (a.ts != b.ts) return a.ts < b.ts;
        return a.name < b.name;
    });

    for (int i = 0; i < res.size(); i++) {
        if (i > 0 && res[i].tws == res[i - 1].tws) res[i].rank = res[i - 1].rank;
        else res[i].rank = i + 1;
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].rank << " " << res[i].name << " " << res[i].tws << " " << res[i].ts << endl;
    }


    return 0;
}
