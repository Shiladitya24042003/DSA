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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) {
            return -1;
        }
        int cnt = 0, ans = -1;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                // inorder.push_back(curr->val);
                cnt++;
                if(cnt == k) {
                    ans =  curr->val;
                }
                curr = curr->right;
            }
            else {
                TreeNode* temp = curr->left;
                while(temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }
                if(temp->right == NULL) {
                    temp->right = curr;
                    curr = curr->left;
                }
                else if(temp->right == curr) {
                    temp->right = NULL;
                    // inorder.push_back(curr->val);
                    cnt++;
                    if(cnt == k) {
                        ans = curr->val;
                    }
                    curr = curr->right;
                    

                }
            }
        }
        return ans;
    }
};