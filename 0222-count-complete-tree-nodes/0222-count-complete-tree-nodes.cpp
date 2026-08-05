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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);
        
        // If left and right heights are equal, it's a perfect binary tree
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) - 1; // 2^leftDepth - 1
        }
        
        // Otherwise, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
private:
    int getLeftDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            depth++;
            node = node->left;
        }
        return depth;
    }
    
    int getRightDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            depth++;
            node = node->right;
        }
        return depth;
    }
};