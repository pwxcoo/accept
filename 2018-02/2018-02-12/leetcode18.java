/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(n^3), S = O(1)
 * describe:    转化为子问题求解。注意对重复的处理。
 */

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int len = nums.length;
        Arrays.sort(nums);
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                int left = j + 1, right = len - 1, temp = target - nums[i] - nums[j];
                
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    
                    if(sum == temp)
                    {
                        res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        while(left < right - 1 && nums[right] == nums[right - 1]) right--;
                        right--;
                    }
                    else if(sum > temp)
                    {
                        right--;
                    }
                    else 
                    {
                        left++;
                    }
                }
                while(j + 1 < len && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < len && nums[i] == nums[i + 1]) i++;
        }
        
        return res;
    }
}