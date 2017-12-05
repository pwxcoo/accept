class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        
        int len = num.length();
        int mark = len;
        for(int i = len - 1; i > 0; i--)
        {
            if(num[i - 1] > num[i])
            {
                mark = i;
                num[i - 1] = num[i - 1] - 1;
            }
        }
        
        for(int i = mark; i < len; i++) num[i] = '9';
        
        return stoi(num);
    }
};