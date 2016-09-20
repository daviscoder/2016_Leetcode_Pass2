// 这是一个非典型DFS...

class Solution {
public:
    void DFS (vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int pos) {
        if (pos <= nums.size()) { // 不push任何元素，出了这个if后，会push至少一个element
            res.push_back (cur);
        }
        for (int i = pos; i < nums.size();) {
            cur.push_back (nums[i]);
            DFS (nums, res, cur, i + 1);
            cur.pop_back ();
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort (nums.begin(), nums.end());
        DFS (nums, res, cur, 0);
        return res;
    }
};
