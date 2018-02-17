/**
 * date: 2018-02-17
 * author: pwxcoo
 * complexity: T = O(n), S = O(1)
 * describe:    排序，数组操作。
 */


/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals.size() <= 1)
            return intervals;
        intervals.sort((i1, i2) -> Integer.compare(i1.start, i2.start));
        
        List<Interval> res = new ArrayList<>();
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        
        for(Interval interval : intervals)
        {
            if(interval.start <= end)
                end = Math.max(end, interval.end);
            else 
            {
                res.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        res.add(new Interval(start, end));
        return res;
    }
}