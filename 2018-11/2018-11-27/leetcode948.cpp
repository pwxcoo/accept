class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0, right = n - 1, res = 0, now = 0;
        
        while (left <= right) {
            if (P >= tokens[left]) {
                P -= tokens[left++];
                res = max(res, ++now);
            } else if (now > 0) {
                now--;
                P += tokens[right--];
            } else break;
        }
        return res;
    }
};