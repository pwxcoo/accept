```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        
        int res = nums[0];
        int mn = res, mx = res;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(mn, mx);
            mx = max(nums[i], nums[i] * mx);
            mn = min(nums[i], nums[i] * mn);
            res = max(res, mx);
        }
        return res;
    }
};
```