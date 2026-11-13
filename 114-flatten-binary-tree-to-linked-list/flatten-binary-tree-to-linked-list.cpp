class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* prev = curr->left;

                // Find the rightmost node of the left subtree
                while (prev->right != nullptr) {
                    prev = prev->right;
                }

                // Connect the original right subtree
                prev->right = curr->right;

                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};