class Solution {
public:
    int sum = 0;
    void DFS (TreeNode* root, bool left) {
        if (root == NULL)
            return;
        else if (left && !root->left && !root->right) {
            sum += root->val;
        }
        DFS (root->left, true);
        DFS (root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        DFS (root, false);
        return sum;
    }
};
