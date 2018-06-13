class Solution {
public:
    int pos(char ch)
    {
        return ch - 'a';
    }
    string shiftingLetters(string S, vector<int>& shifts) {
        long long len = shifts.size();
        long long sum = 0;
        char result[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        string res = "";
        for(long long i = len - 1; i >= 0; i--)
        {
            sum += shifts[i];
            if(i < S.length())
                res = result[(pos(S[i]) + sum) % 26] + res;
            
        }
        return res;
    }
};