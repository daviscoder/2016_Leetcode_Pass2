class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int l = 0, r = 0, res = INT_MAX, sum = nums[0];
        while (r < nums.size()) {
            if (l > r) {
                return 1;
            }
            if (sum >= s) {
                sum -= nums[l];
                res = min (res, r - l + 1);
                l++;
            }
            else {
                r++;
                sum += nums[r];
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
