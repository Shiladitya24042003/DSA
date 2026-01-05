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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int indx = 0;
        return build(preorder, indx, INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int& indx, int bound) {
        if(indx == preorder.size() || preorder[indx] > bound) return NULL;

        TreeNode* root = new TreeNode(preorder[indx++]);
        root->left = build(preorder, indx, root->val);
        root->right = build(preorder, indx, bound);
        return root;
    }
};
