class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> bs;
        for (auto building: buildings) {
            bs.push_back({building[0], -building[2]});
            bs.push_back({building[1], building[2]});
        }
        sort(bs.begin(), bs.end(), [](const pair<int,int> &a, const pair<int, int> &b) -> bool
             {
                 return a.first != b.first ? a.first < b.first : a.second < b.second;
             });
        
        
        multiset<int> st;
        st.insert(0);
        
        vector<pair<int, int>> res;
        for (auto b: bs) {
            int now = *st.rbegin();
            if (b.second < 0)
                st.insert(-b.second);
            else
                st.erase(st.find(b.second));
            
            if (now != *st.rbegin())
                res.push_back({b.first, *st.rbegin()});
        }
        return res;
    }
};