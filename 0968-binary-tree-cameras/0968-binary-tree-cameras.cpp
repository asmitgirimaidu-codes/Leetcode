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
    int cameras = 0;

    // Returns:
    // 0: Node is not monitored and needs a camera
    // 1: Node has a camera
    // 2: Node is monitored by a child's camera (no camera needed here)
    int dfs(TreeNode* node) {
        if (!node) return 2; // Null nodes are considered fully monitored
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // If any child is not monitored, we must place a camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }
        
        // If any child has a camera, this node is monitored
        if (left == 1 || right == 1) {
            return 2;
        }
        
        // Otherwise, children are covered, but this node is not monitored yet
        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        // If root returns 0, it means the root itself is not monitored, so we need one more camera
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};