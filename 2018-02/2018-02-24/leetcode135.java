/**
 * date: 2018-02-24
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    贪心,双向遍历
 */

class Solution {
    public int candy(int[] ratings) {
        if(ratings.length == 0) return 0;
        int[] res = new int[ratings.length];
        res[0] = 1;
        for(int i = 0; i < ratings.length - 1; i++)
        {
            if(ratings[i + 1] > ratings[i]) res[i + 1] = res[i] + 1;
            else res[i + 1] = 1;
        }
        
        int ans = 0;
        for(int i = ratings.length - 1; i > 0; i--)
        {
            if(ratings[i - 1] > ratings[i] && res[i - 1] <= res[i]) res[i - 1] = res[i] + 1;
            ans += res[i];
        }
        
        return ans + res[0];
    }
}