class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.count(nums[i])) {
                res.push_back (myMap[nums[i]]);
                res.push_back (i);
                break;
            }
            myMap[target - nums[i]] = i;
        }
        return res;
    }
};
