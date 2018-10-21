## Intuition

Store previous elements appeared in map, search it with $$O(1)$$.

- Time Complexity: $$O(n)$$
- Space Complexity: $$O(n)$$


## Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int sz = nums.size();
        
        vector<int> res;
        for (int i = 0; i < sz; i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
```