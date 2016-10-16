// O n * log (sum(nums))

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0)
            return 0;
        long high = 0, low = 0;
        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
        }
        low = high / m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int n = m, cnt = 0;
            bool valid = true;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > mid) {
                    valid = false;
                    break;
                }
                if (cnt + nums[i] > mid) {
                    cnt = 0;
                    n--;
                }
                cnt += nums[i];
                if (n == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
