class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int sum = 1, res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum *= nums[i];
            if(sum < k)
            {
                res += i - left + 1;
            }
            else
            {
                while(sum >= k && left <= i)
                {
                    sum /= nums[left++];
                }
                res += i - left + 1;
            }
        }
        return res;
    }
};