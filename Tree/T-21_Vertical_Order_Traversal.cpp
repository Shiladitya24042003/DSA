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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> queue;
        queue.push({root, {0, 0}});
        while(!queue.empty()) {
            auto it = queue.front(); queue.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;

            nodes[vertical][level].insert(node->val);
            if(node->left) {
                queue.push({node->left, {vertical-1, level+1}});
            }
            if(node->right) {
                queue.push({node->right, {vertical+1, level+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto vertical: nodes) {
            vector<int> columns;
            for(auto it: vertical.second) {
                columns.insert(columns.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(columns);
        }
        return ans;
    }
};
/*Just mark the verticals and levels and stor them in a 
data structure like coordinates and ultimately get the answer*/