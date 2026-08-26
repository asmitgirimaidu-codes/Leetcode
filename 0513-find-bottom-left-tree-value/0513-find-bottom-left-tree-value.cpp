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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftmostVal = root->val;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            leftmostVal = curr->val;
            
            // Push right first, then left, so the leftmost node of the next level is processed last
            if (curr->right) {
                q.push(curr->right);
            }
            if (curr->left) {
                q.push(curr->left);
            }
        }
        
        return leftmostVal;
    }
};