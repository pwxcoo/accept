/**
 * date: 2018-02-16
 * author: pwxcoo
 * complexity: T = O(n^2), S = O(n)
 * describe:    https://drscdn.500px.org/photo/130178585/m%3D2048/300d71f784f679d5e70fadda8ad7d68f
 *              别人的思路。就是 `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]` 
 *              可是跟我自己写的裸写的办法，直接每次定位到字符串某个位置直接运算，居然还是我的方法快。。虽然别人的思路很清奇。。
 */

class Solution {
    public String multiply(String num1, String num2) {
        int n = num1.length(), m = num2.length();
        int[] res = new int[n + m];
        
        int temp;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                temp = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                
                res[i + j + 1] += temp;
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] = res[i + j + 1] % 10;
            }
        }
        
        StringBuffer sb = new StringBuffer();
        for(int a : res) if(!(sb.length() == 0 && a == 0))sb.append(a);
        return sb.length() == 0 ? "0" :sb.toString();
    }
}