/**
 * O(n), O(1).
 * Using inorder traversal and compare the current node with the previous visited node.
 * empty tree. valid tree. Left subtree invalid, right subtree invalid.
 */

class Solution {
public:
    TreeNode* previous = NULL;
    bool helper (TreeNode* root) {
        if (root == NULL) return true;
        if (helper (root->left) == false)
            return false;
        if (previous != NULL && root->val <= previous->val)
            return false;
        previous = root;
        return helper (root->right);
    }

    bool isValidBST(TreeNode* root) {
        return helper (root);
    }
};
