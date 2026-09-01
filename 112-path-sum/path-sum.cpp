class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Empty tree
        if (root == NULL)
            return false;

        // Subtract current node's value
        targetSum -= root->val;

        // Check if we reached a leaf
        if (root->left == NULL && root->right == NULL)
        {
            return targetSum == 0;
        }

        // Search left or right subtree
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};