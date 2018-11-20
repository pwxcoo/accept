class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> graph(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = compute(A[i], A[j]);
                graph[j][i] = compute(A[j], A[i]);
            }
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> pre(1 << n, vector<int>(n, -1));
        
        int mn = INT_MAX, last = -1;
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    int prev = i - (1 << j);
                    if (!prev) {
                        dp[i][j] = A[j].size();
                    } else {
                        for (int k = 0; k < n; k++) {
                            if (dp[prev][k] < INT_MAX && dp[i][j] > dp[prev][k] + graph[k][j]) {
                                dp[i][j] = dp[prev][k] + graph[k][j];
                                pre[i][j] = k;
                            }
                        }
                    }    
                }
                
                if (i == (1 << n) - 1 && dp[i][j] < mn) {
                    mn = dp[i][j];
                    last = j;
                }
            }
        }
        
        stack<int> st;
        int now = (1 << n) - 1;
        while (last != -1) {
            st.push(last);
            int cur = now;
            now -= 1 << last;
            last = pre[cur][last];
        }
        
        last = st.top(); st.pop();
        string res = A[last];
        while (!st.empty()) {
            int top = st.top(); st.pop();
            res += A[top].substr(A[top].size() - graph[last][top]);
            last = top;
        }
        return res;
    }
private:
    int compute(string a, string b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (b.compare(0, n - i, a.substr(i)) == 0) {
                return b.size() - n + i;
            }
        }
        return b.size();
    }
};