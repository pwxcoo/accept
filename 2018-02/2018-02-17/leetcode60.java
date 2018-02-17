/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    数学
 */

class Solution {
    public String getPermutation(int n, int k) {
        StringBuffer sb = new StringBuffer();
        int[] toChoose = new int[n];
        for(int i = 1; i <= n; i++)
            toChoose[i - 1] = i;
        int f = 1;
        for(int i = 1; i <= n; i++)
        {
            f *= i;
        }
        
        for(int i = n; i >= 1; i--)
        {
            f /= i;
            int temp = (k - 1) / f;
            sb.append(toChoose[temp]);
            k = (k - 1) % f + 1;
            for(int j = temp; j < n - 1; j++)
                toChoose[j] = toChoose[j + 1];
        }
        return sb.toString();
        
    }
}