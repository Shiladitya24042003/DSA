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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL) return newNode;
        TreeNode* curr = root;
        TreeNode* prev = curr;
        while(curr) {
            prev = curr;
            if(val > curr->val) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        
        if(val > prev->val) prev->right = newNode;
        else prev->left = newNode;
        return root;
    }
};