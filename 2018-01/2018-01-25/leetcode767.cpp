class Solution {
public:
    string reorganizeString(string S) {
        int len = S.length();
        //排序一波
        vector<int> cnt(26, 0);
        for(char ch: S) cnt[ch - 'a'] += 100;
        for(int i = 0; i < 26; i++) cnt[i] += i;
        sort(cnt.begin(), cnt.end());
        
        string res = S;
        int pos = 1;
        for(int i = 0; i < 26; i++){
            int sum = cnt[i] / 100;
            char ch = cnt[i] % 100 + 'a';
            if(sum > (len + 1) / 2) return "";
            
            for(int j = 0; j < sum; j++){
                if(pos >= len) pos = 0;
                res[pos] = ch;
                pos += 2;
            }
        }
        return res;
    }
};