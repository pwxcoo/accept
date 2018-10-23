```cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int sz = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) -> bool {
            return a.start != b.start ? a.start < b.start : a.end < b.end;
        });
        
        vector<Interval> res;
        for (int i = 0; i < sz; )
        {
            int j = i + 1;
            while (j < sz && intervals[j].start <= intervals[i].end)
                intervals[i].end = max(intervals[i].end, intervals[j++].end);
            res.push_back(intervals[i]);
            i = j;
        }
        return res;
    }
};
```