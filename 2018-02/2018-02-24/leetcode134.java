/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    贪心
 */


class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0, start = 0, tank = 0;
        for(int i = 0; i < gas.length; i++)
        {
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        return total + tank < 0 ? -1 : start;
    }
}