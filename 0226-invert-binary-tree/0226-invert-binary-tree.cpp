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
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the tree is empty, return null
        if (root == nullptr) {
            return nullptr;
        }
        
        // Recursively invert the left and right subtrees
        TreeNode* leftSub = invertTree(root->left);
        TreeNode* rightSub = invertTree(root->right);
        
        // Swap the left and right children
        root->left = rightSub;
        root->right = leftSub;
        
        return root;
    }
};