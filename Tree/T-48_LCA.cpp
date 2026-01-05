/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* node = NULL;
        if(p->val < root->val && q->val < root->val) {
            node = lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val) {
            node = lowestCommonAncestor(root->right, p, q);
        }
        else node = root;

        return node;
    }
};