/**
 * 使用inorder traversal的思想，保存前一个节点与当前节点value比较.
 */
class Solution {
public:
    bool inorder (TreeNode* root, TreeNode* &prev) {
        if (root == NULL)
            return true;
        if (inorder (root->left, prev) == false)
            return false;
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        return inorder (root->right, prev);
        
    }

    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        return inorder (root, prev);
    }
};
