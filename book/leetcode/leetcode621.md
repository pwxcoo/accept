## Intuition

Image each cycle as a bucket, put a task in each bucket in turn, simulate it then get a formula:

- `mx` is the most task
- `n` is the number of tasks
- `same` is the number of task same with the most task

$$(mx - 1) * (n + 1) + same$$

- Time Complexity: $$O(n)$$
- Space Complexity: $$O(1)$$

## Solution

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        vector<int> cnt(26, 0);
        int mx = 0;
        int same = 1;
        for (auto t: tasks)
        {
            cnt[t - 'A']++;
            if (cnt[t - 'A'] > mx)
            {
                mx = cnt[t - 'A'];
                same = 1;
            }
            else if (cnt[t - 'A'] == mx)
            {
                same++;
            }
        }
                
        return max((mx - 1) * (n + 1) + same, sz);
    }
};
```