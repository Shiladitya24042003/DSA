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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        long long ans = 0; // Use long long for width
        queue<pair<TreeNode*, long long>> q; // Use long long for indices
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            long long mmin = q.front().second; 
            long long first, last;
            
            for(int i=0; i<size; i++){
                // Subtract mmin to keep indices small at each level
                long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0) first = cur_id;
                if(i == size - 1) last = cur_id;
                
                if(node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if(node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};