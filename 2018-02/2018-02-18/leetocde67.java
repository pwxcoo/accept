/**
 * date: 2018-02-18
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    字符串操作
 */

class Solution {
    public String addBinary(String a, String b) {
        int carry = 0;
        int apos = a.length() - 1, bpos = b.length() - 1;
        StringBuffer sb = new StringBuffer();
        while(carry != 0 || apos >= 0 || bpos >= 0)
        {
            int temp = (apos >= 0 ? a.charAt(apos) - '0' : 0) + (bpos >= 0 ? b.charAt(bpos)  - '0': 0) + carry;
            sb.append(temp % 2);
            carry = temp / 2;
            apos--; bpos--;
        }
        return sb.reverse().toString();
    }
}