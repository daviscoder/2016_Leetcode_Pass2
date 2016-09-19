/**
 * 一定要用BFS，不能用DFS，因为每个col的元素要求按顺序....
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> myMap;
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        if (root == NULL)
            return res;
        q.push ({root, 0});
        while (q.empty() == false) {
            TreeNode * p = q.front().first;
            int col = q.front().second;
            q.pop();
            myMap[col].push_back (p->val);
            if (p->left)
                q.push({p->left, col - 1});
            if (p->right)
                q.push({p->right, col + 1});
        }
        for (auto i: myMap) {
            res.push_back(i.second);
        }
        return res;
    }
};
