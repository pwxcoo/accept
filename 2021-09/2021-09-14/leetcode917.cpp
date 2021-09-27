class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.length();
        int left = 0, right = len - 1;
        
        while (left < right) {
            while (left < right && !isChar(s[left])) left++;
            while (right > left && !isChar(s[right])) right--;
            
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        return s;
    }
    
    bool isChar(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};