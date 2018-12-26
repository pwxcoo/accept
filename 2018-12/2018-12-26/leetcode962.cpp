class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> st;
        
        for (int i = 0; i < A.size(); i++) {
            if (st.empty() || A[i] < A[st.top()]) {
                st.push(i);
            }
        }
        
        int res = 0;
        for (int i = A.size() - 1; i >= 0 && !st.empty(); i--) {
            while (!st.empty() && A[st.top()] <= A[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        
        return res;
    }
};