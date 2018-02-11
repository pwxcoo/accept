/**
 * date: 2018-02-11
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    转换罗马字符。跟进制转换没什么区别。就是很多人对罗马字符不熟悉。
 */


class Solution {
    public String intToRoman(int num) {
        int[] values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        StringBuilder sb = new StringBuilder();

        for(int i = 0;i < values.length; i++) {
            while(num >= values[i]) {
                num -= values[i];
                sb.append(strs[i]);
            }
        }
        return sb.toString();
    }
}