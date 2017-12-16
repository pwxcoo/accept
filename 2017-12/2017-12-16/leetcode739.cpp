class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int len = temperatures.size();
        vector<int> res(len, 0);
        for(int i = 0; i < len; i++)
        {
            while(!st.empty() && temperatures[i] > st.top().second)
            {
                auto top = st.top(); st.pop();
                res[top.first] = i - top.first;
            }
            st.push(make_pair(i,temperatures[i]));
        }
        while(!st.empty())
        {
            auto top = st.top(); st.pop();
            res[top.first] = 0;
        }
        return res;
    }
};