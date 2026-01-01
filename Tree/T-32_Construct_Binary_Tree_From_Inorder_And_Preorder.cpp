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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, map<int, int> &mpp) {
        if(inStart > inEnd || preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndx = mpp[preorder[preStart]];
        int len = rootIndx - inStart;
        root->left = build(preorder, inorder, preStart+1, preStart + len, inStart, rootIndx-1, mpp);
        root->right = build(preorder, inorder, preStart + len + 1, preEnd, rootIndx+1, inEnd, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root =  build(preorder, inorder, 0, n-1, 0, n-1, mpp);
        return root;
    }
};