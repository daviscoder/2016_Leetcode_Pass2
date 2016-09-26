/**
 * O (n), O(height)
 * post order traversal.
class Solution {
public:
    TreeNode * prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten (root->right);
        flatten (root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
 
/**
 * O (n), O (height).
 * preorder traversal: keep the previous visited node and append.
 */
class Solution {
public:
    TreeNode * prev = NULL;
    void preOrder (TreeNode * root) {
        if (root == NULL)
            return;
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        root->left = NULL; // Don't forget to set left tree as NULL.
        if (prev)
            prev->right = root;
        prev = root;
        preOrder (left);
        preOrder (right);
    }
    void flatten(TreeNode* root) {
        preOrder (root);
    }
};

