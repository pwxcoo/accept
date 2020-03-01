## Intuition

一个各个评委的排序结果，然后得到最终的结果。

----

主要是排序的规则。


## Solution

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].length();
        auto r = vector<pair<int, vector<int>>>(26, make_pair(0, vector<int>(n, 0)));
        for (int i = 0; i < 26; i++) {
            r[i].first = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < votes.size(); j++) {
                r[votes[j][i]- 'A'].second[i]++;
            }
        }

        sort(r.begin(), r.end(), [&](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) -> bool {
            for (int i = 0; i < n; i++) {
                if (a.second[i] == b.second[i]) continue;
                else return a.second[i] > b.second[i];
            }
            return a.first < b.first;
        });

        string res = "";
        for (int i = 0; i < n; i++) {
            res += 'A' + r[i].first;
        }

        return res;
    }
};
```

时间复杂度：$$O(nlogn)$$