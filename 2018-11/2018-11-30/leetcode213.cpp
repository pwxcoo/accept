class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
    int helper(vector<int>& nums, int left, int right) {
        if (right < left) return 0;
        if (right == left) return nums[left];
        
        int ppre = nums[left], pre = nums[left + 1];
        int res = max(pre, ppre);
        
        for (int i = left + 2; i <= right; i++) {
            res = max(pre, ppre + nums[i]);
            ppre = max(ppre, pre); pre = res;
        }
        return res;
    }
};