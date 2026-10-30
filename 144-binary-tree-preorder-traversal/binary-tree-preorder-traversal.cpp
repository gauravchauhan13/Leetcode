class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            // Push right first, so left is processed first
            if (curr->right != nullptr) {
                st.push(curr->right);
            }

            if (curr->left != nullptr) {
                st.push(curr->left);
            }
        }

        return ans;
    }
};