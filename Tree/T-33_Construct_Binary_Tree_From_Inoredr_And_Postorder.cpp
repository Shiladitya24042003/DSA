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
    TreeNode* build(vector<int> &postorder, vector<int> &inorder, int postStart, int postEnd, int inStart, int inEnd, map<int, int> &mpp) {
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndx = mpp[postorder[postEnd]];
        int len = rootIndx - inStart;
        root->left = build(postorder, inorder, postStart, postStart+len-1, inStart, rootIndx-1, mpp);
        root->right = build(postorder, inorder, postStart+len, postEnd-1, rootIndx+1, inEnd, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root =  build(postorder, inorder, 0, n-1, 0, n-1, mpp);
        return root;
    }
};