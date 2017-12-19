class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int len = cost.length;
        int one = 0, two = 0;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            res = Math.min(cost[i] + one, cost[i] + two);
            two = one;
            one = res;
        }
        return Math.min(one, two);
    }
}