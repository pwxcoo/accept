## Intuition

Skyline Problem

-----

- 左 `{x, -y}`, 右 `{x, y}`，然后放到一个集合里，集合大小为 `2N`，然后排序一波。（为什么左边界要 `-y` 呢，因为右边界表示的是消失，希望在消失前能先把这里出现的边界全部拿出来先。）
- 开始遍历，维护一个当前集合的最大值，有变化则说明是一个轮廓，加入到结果集。

## Solution

```cpp
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> bs;
        for (auto building: buildings) {
            bs.push_back({building[0], -building[2]});
            bs.push_back({building[1], building[2]});
        }
        sort(bs.begin(), bs.end(), [](const pair<int,int> &a, const pair<int, int> &b) -> bool
             {
                 return a.first != b.first ? a.first < b.first : a.second < b.second;
             });
        
        
        multiset<int> st;
        st.insert(0);
        
        vector<pair<int, int>> res;
        for (auto b: bs) {
            int now = *st.rbegin();
            if (b.second < 0)
                st.insert(-b.second);
            else
                st.erase(st.find(b.second));
            
            if (now != *st.rbegin())
                res.push_back({b.first, *st.rbegin()});
        }
        return res;
    }
};
```