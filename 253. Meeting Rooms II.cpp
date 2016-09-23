/**
 * O(n logn), O(1)
 * 空向量，一门课，没overlap，夸2门课，跨3门课
 */
class Solution {
public:
    static bool myComparator (Interval& i, Interval& j) {
        return i.start <= j.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort (intervals.begin(), intervals.end(), myComparator);
        if (intervals.size() == 0)
            return 0;
        int res = 0;
        while (intervals.size() > 0) {
            int cur = INT_MIN;
            res++;
            for (int i = 0; i < intervals.size();) {
                if (cur <= intervals[i].start) {
                    cur = intervals[i].end;
                    intervals.erase (intervals.begin() + i);
                }
                else {
                    i++;
                }
            }
        }
        return res;
    }
};
