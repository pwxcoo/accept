class Solution {
    /*
    1. 偶函数
    2. sum = {1, 2, ..., k}, delta = sum - target
        2.1 delta为偶， 可证为k
        2.2 delta为奇， 加上一个奇数就可以

    */
    public int reachNumber(int target) {
        target = Math.abs(target);
        int k = 0;
        while(target > 0)
        {
            target -= ++k;
        }
        
        return target % 2 == 0 ? k : (k + 1 + k % 2);
    }
}