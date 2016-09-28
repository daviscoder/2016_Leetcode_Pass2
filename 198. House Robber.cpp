class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        int house0 = 0, house1 = nums[0], house2 = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int cur = max (house0, house1) + nums[i];
            house0 = house1;
            house1 = house2;
            house2 = cur;
        }
        return max (house1, house2);
    }
};
