/**
 * Apply DP to solve. DFS is not efficient enough.
 * 每行长度为target + 1. 每添加一个row 新添加进来一个元素. 此题还需要再复习！
 **/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> comb (target + 1, 0);
        comb[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    comb[i] += comb[i - nums[j]];
                }
            }
        }
        return comb[target];
    }
};
