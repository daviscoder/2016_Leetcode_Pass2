/**
 * O(n), O(n)
 * root为空，左子树为空，右子树为空，某Vertical Level 有overlap，有间隔vertical level等等.
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> myMap;
        if (root == NULL)
            return res;
        queue<pair <TreeNode*, int>> q;
        q.push({root, 0});
        while (q.empty() == false) {
            TreeNode * cur = q.front().first;
            int col = q.front().second;
            myMap[col].push_back (cur->val);
            q.pop();
            if (cur->left) {
                q.push({cur->left, col - 1});
            }
            if (cur->right) {
                q.push({cur->right, col + 1});
            }
        }
        for (map<int, vector<int>>::iterator i = myMap.begin(); i != myMap.end(); i++) {
            res.push_back (i->second);
        }
        return res;
    }
};
