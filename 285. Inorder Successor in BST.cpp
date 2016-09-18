
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL)
            return NULL;
        if (root->val <= p->val) // 一定要带等号，因为当p->val == root->val的时候，p的successor在右边.
            return inorderSuccessor (root->right, p);
        else {
            TreeNode *left = inorderSuccessor (root->left, p);
            return left == NULL? root : left;
        }
    }
};
