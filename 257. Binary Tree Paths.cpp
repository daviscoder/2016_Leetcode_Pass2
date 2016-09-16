/**
 * 注意判断左右字数均为空的情况，把root->val push_back不能忘！
 * 
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL)
            return res;
        if (!root->left && !root->right) {
            res.push_back (to_string(root->val));
            return res;
        }
        vector<string> left = binaryTreePaths (root->left);
        vector<string> right = binaryTreePaths (root->right);
        for (int i = 0; i < left.size(); i++)
            res.push_back (to_string(root->val) + "->" + left[i]);
        for (int i = 0; i < right.size(); i++)
            res.push_back (to_string(root->val) + "->" + right[i]);
        return res;
    }
};
