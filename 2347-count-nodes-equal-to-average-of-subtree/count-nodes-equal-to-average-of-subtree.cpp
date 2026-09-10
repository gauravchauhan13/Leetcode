class Solution {
public:
    int count = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if (sum / nodes == root->val)
            count++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};