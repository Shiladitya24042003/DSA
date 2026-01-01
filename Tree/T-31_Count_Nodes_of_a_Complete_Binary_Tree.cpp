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
        if(root == NULL) return 0;

        int lh = leftSubTreeHeight(root);
        int rh = rightSubTreeHeight(root);

        if(lh == rh) return (1<<lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int leftSubTreeHeight(TreeNode* root) {
        int hight = 0;
        while(root) {
            root = root->left;
            hight++;
        }
        return hight;
    }
    int rightSubTreeHeight(TreeNode* root) {
        int hight = 0;
        while(root) {
            root = root->right;
            hight++;
        }
        return hight;
    }
};