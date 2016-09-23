/**
 * O(n), O(1)
 * Test case: sorted, unsorted, 一个, 两个不干涉, 两个干涉, 多个干涉

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
    static bool myComparator (Interval& i, Interval& j) {
        if (i.start < j.start)
            return true;
        else if (i.start == j.start && i.end < j.end)
            return true;
        return false;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort (intervals.begin(), intervals.end(), myComparator);
        for (int i = 0; i < (int)intervals.size() - 1;) {
            if (intervals[i].end >= intervals[i + 1].start) {
                intervals[i].end = max (intervals[i].end, intervals[i + 1].end);
                intervals.erase (intervals.begin() + i + 1);
            }
            else {
                i++;
            }
        }
        return intervals;
    }
};
