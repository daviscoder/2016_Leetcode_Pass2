// 这题得再好好想想...

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if (length == 0)
            return 0;
        int start = 0, end = citations.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (citations[mid] >= length - mid)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return length - start;

    }
};
