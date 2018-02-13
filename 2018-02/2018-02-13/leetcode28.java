/**
 * date: 2018-02-13
 * author: pwxcoo
 * complexity: T = O(n*m), S = O(1)
 * describe:    暴力。其实可以用 KMP ，但是太麻烦了，懒得写。
 */

class Solution {
    public int strStr(String haystack, String needle) {
        for(int i = 0; ; i++)
        {
            for(int j = 0; ; j++)
            {
                if(j == needle.length()) return i;
                if(i + j >= haystack.length()) return -1;
                if(haystack.charAt(i + j) != needle.charAt(j)) break;
            }
        }
    }
}