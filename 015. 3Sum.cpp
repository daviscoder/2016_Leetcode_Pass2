/**
 * 去重问题：第一个数试过后再跳后面和他相同的
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort (nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j++; k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (sum < 0) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                }
                else {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
            while (nums[i] == nums[i + 1] && i < (int)nums.size() - 2)
                i++;
        }
        return res;
    }
};
