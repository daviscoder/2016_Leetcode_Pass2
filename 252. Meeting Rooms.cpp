/**
 * 记住sort 自定义比较器的写法...
 */
class Solution {
public:
    static bool myComparator (Interval& a, Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort (intervals.begin(), intervals.end(), myComparator);
        for (int i = 0; i < (int)intervals.size() - 1; i++)
            if (intervals[i].end > intervals[i + 1].start)
                return false;
        return true;
    }
};
