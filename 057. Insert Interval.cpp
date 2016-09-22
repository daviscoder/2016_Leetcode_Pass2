// already sorted and the original do not need to be merged
// O(n), O(1)
// testcase: 开头, 结尾, 中间不干涉, 中间干涉1-3个

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0)
            return vector<Interval> (1, newInterval);
        int index = 0;
        while (index < intervals.size() && intervals[index].end < newInterval.start)
            index++;

        while (index < intervals.size() && intervals[index].start <= newInterval.end) {
            newInterval.start = min (newInterval.start, intervals[index].start);
            newInterval.end = max (newInterval.end, intervals[index].end);
            intervals.erase (intervals.begin() + index);
        }
        intervals.insert (intervals.begin() + index, newInterval);
        return intervals;
    }
};
