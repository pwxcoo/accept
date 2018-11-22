class Solution {
public:
    bool isok(string stamp, string target, int start) {
        bool flag = false;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[start + i] == stamp[i]) {
                flag = true;
                continue;
            }
            if (target[start + i] != '?') return false;
        }
        return flag;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();
        stack<int> st;
        bool finish = false;
        string r(m, '?');
        while (!finish) {
            finish = true;
            for (int i = 0; i <= n - m; i++) {
                if (isok(stamp, target, i)) {
                    finish = false;
                    target.replace(i, m, r);
                    st.push(i);
                    break;
                }
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (target[i] != '?') {
                return res;
            }
        }
          
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};