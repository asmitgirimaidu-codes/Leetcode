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
    bool dfs(TreeNode* root, vector<int>& voyage, int& i, vector<int>& result) {
        if (!root) return true;
        
        // The current root must match the expected voyage value
        if (root->val != voyage[i++]) return false;
        
        // If the left child exists and does not match the next voyage value, we must flip
        if (root->left && root->left->val != voyage[i]) {
            result.push_back(root->val);
            // Traverse right first, then left (because of the flip)
            return dfs(root->right, voyage, i, result) && dfs(root->left, voyage, i, result);
        }
        
        // Otherwise, standard pre-order traversal: left then right
        return dfs(root->left, voyage, i, result) && dfs(root->right, voyage, i, result);
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        int i = 0;
        if (dfs(root, voyage, i, result)) {
            return result;
        }
        return {-1};
    }
};