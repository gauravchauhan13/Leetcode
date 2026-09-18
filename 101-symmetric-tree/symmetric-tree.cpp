class Solution {
public:
    bool mirror(TreeNode* left, TreeNode* right) {
        // Both are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL, the other is not
        if (left == NULL || right == NULL)
            return false;

        // Values are different
        if (left->val != right->val)
            return false;

        // Compare opposite sides
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};