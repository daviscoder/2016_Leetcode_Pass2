// 6:05

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (isBadVersion (mid) == false)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};
