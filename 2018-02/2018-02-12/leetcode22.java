/**
 * date: 2018-02-12
 * author: pwxcoo
 * complexity: T = O(4^n / sqrt(n)), S = O(4^n / sqrt(n))
 * describe:    回溯。
 */

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtracking(res, "", 0, 0, n);
        return res;
    }
    
    void backtracking(List<String> res, String now, int open, int close, int n)
    {
        if(close == n)
        {
            res.add(now);
            return;
        }
        
        if(close < open) backtracking(res, now + ")", open, close + 1, n);
        if(open < n) backtracking(res, now + "(", open + 1, close, n);
        
    }
}