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
        else if (i.start == j.start)
            return i.end < j.end;
        else
            return false;
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        sort (intervals.begin(), intervals.end(), myComparator);
        int cnt = 0;
        while (intervals.size() > 0) {
            cnt++;
            int current = intervals[0].end, i = 0;
            intervals.erase(intervals.begin());
            while (i < intervals.size()) {
                if (current > intervals[i].start) {
                    i++;
                }
                else {
                    current = intervals[i].end;
                    intervals.erase (intervals.begin() + i);
                }
            }
        }
        return cnt;
    }
};
