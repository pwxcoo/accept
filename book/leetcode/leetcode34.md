```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        int left = 0, right = sz - 1;
        
        vector<int> res(2, -1);
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (sz == 0 || nums[left] != target) return res;
        res[0] = left;
        
        right = sz - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2 + 1;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        res[1] = left;
        return res;
    }
};
```