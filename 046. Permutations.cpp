class Solution {
public:
    void dfs (vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, vector<bool>& visited) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == false) {
                cur.push_back(nums[i]);
                visited[i] = true;
                dfs (res, cur, nums, visited);
                visited[i] = false;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        dfs(res, cur, nums, visited);
        return res;
    }
};
