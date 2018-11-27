class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int n = pushed.size();
        int pu = 0, po = 0;
        while (po < n) {
            while (st.empty() || st.top() != popped[po]) {
                if (pu >= n) return false;
                st.push(pushed[pu++]);
            }
            po++;
            st.pop();
        }
        return true;
    }
};