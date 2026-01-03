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
    int hight(TreeNode* root, int &diameter) {
        if(!root) return -1;

        int left = 1+hight(root->left, diameter);
        int right = 1+hight(root->right, diameter);
        diameter = max(diameter, left+right);
        return max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int h = hight(root, diameter);
        return diameter;
    }
};