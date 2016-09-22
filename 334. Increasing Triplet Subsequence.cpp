class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            // The reason to keep <= instead of < is because arr[i] < arr[j] < arr[k] has to be strictly kept.
            if (nums[i] <= small) // Update small when nums[i] is the smallest currently.
                small = nums[i];
            else if (nums[i] <= big) // Update big when nums[i] > small but no larger than big.
                big = nums[i];
            else
                return true;
        }
        return false;
    }
};
