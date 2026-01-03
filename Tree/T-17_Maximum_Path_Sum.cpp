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
    int hight(TreeNode* root, int &sum) {
        if(!root) return 0;

        int left = max(0, hight(root->left, sum));
        int right = max(0, hight(root->right, sum));
        sum = max(sum, left+right+root->val);
        
        return max(left, right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = -1e9;
        int h = hight(root, sum);
        return sum;
    }
};