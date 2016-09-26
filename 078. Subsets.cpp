class Solution {
public:
    void DFS (vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int pos) {
        res.push_back (cur);
        if (pos >= nums.size())
            return;
        for (int i = pos; i < nums.size(); i++) {
            cur.push_back (nums[i]);
            DFS (res, cur, nums, i + 1);
            cur.pop_back ();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        DFS (res, cur, nums, 0);
        return res;
    }
};
