
// Foursum reduce to 3 sum... O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        res.push_back(tmp);
                        k++; l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target) {
                        k++;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                    }
                    else {
                        l--;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
