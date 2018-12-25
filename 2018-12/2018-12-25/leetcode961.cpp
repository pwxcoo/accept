class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (auto a: A) {
            if (s.count(a) > 0) return a;
            s.insert(a);
        }
    }
};