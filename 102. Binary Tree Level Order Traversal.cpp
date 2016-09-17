class Solution {
public:
    void helper (vector<vector<int>>& res, int level, TreeNode* root) {
        if (root == NULL)
            return;
        if (level >= res.size())
            res.push_back (vector<int> ());
        res[level].push_back (root->val);
        helper (res, level + 1, root->left);
        helper (res, level + 1, root->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper (res, 0, root);
        return res;
    }
};
