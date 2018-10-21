```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len - 1;
        
        int res = 0;
        while (left < right)
        {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
```