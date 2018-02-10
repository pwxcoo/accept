/**
 * date: 2018-02-10
 * author: pwxcoo
 * complexity: T = O(n), S = O(n)
 * describe:    反转一个整数，考虑溢出
 */

class Solution {
    public int reverse(int x) {
        int result = 0;
        
        while(x != 0)
        {
            int temp = x % 10;
            
            int newResult = result * 10 + temp;
            if((newResult - temp) / 10 != result) return 0;
            
            result = newResult;
            x /= 10;
        }
        
        return result;
    }
}