class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int sz = A.size();
        vector<int> dp(sz);
        
        stack<int> st;
        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < sz; i++)
        {
            while(!st.empty() && A[i] < A[st.top()])
                st.pop();
            
            long long now;
            if (st.empty())
            {
                now = (i + 1) * A[i] % mod;
            }
            else
            {
                now = (dp[st.top()] + (i - st.top()) * A[i]) % mod;
            }
            st.push(i);
            dp[i] = now;
            res = (res + now) % mod;
        }
        return res;
    }
};