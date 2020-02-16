## Intuition

一组 event，有 `startTime` 和 `endTime`。一天只能参加一个 event，计算最多能参加多少个 event。

----

贪心。维护一个优先队列，每天添加到达 `startTime` 的 event，剔除过期的 event，然后找出当前最快截止的 event 来消费。（不到 ddl 就不做~）

## Solution

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0];  
        });
        
        int res = 0;
        int now = 0;
        for (int d = 1; d <= 1e5 && (now < events.size() || !pq.empty()); d++) {
            while (now < events.size() && events[now][0] <= d) pq.push(events[now++][1]);
            
            while (!pq.empty() && pq.top() < d) pq.pop();
            if (!pq.empty()) {
                res++; pq.pop();
            }
        }
        return res;
    }
};
```

时间复杂度：$$O(nlogn)$$