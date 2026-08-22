/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Helper function returns a pair: { rob_current, not_rob_current }
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // If we rob this node, we cannot rob its children
        int rob_current = node->val + left.second + right.second;

        // If we don't rob this node, we can choose to rob or not rob its children (take the max of both)
        int not_rob_current = max(left.first, left.second) + max(right.first, right.second);

        return {rob_current, not_rob_current};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};