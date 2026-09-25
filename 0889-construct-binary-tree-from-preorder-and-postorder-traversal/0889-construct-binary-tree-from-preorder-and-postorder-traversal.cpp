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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& postorder, int postStart, int postEnd, 
                    unordered_map<int, int>& postMap) {
        if (preStart > preEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;

        // The element right after root in preorder is the root of the left subtree
        int leftRootVal = preorder[preStart + 1];
        int mid = postMap[leftRootVal];
        int leftSize = mid - postStart + 1;

        root->left = build(preorder, preStart + 1, preStart + leftSize, 
                           postorder, postStart, mid, postMap);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, 
                            postorder, mid + 1, postEnd - 1, postMap);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        for (int i = 0; i < postorder.size(); ++i) {
            postMap[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postMap);
    }
};