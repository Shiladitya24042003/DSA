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
private:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root, parent);

        unordered_map<TreeNode*, int> visited_node;
        queue<TreeNode*> queue;
        queue.push(target);
        visited_node[target] = 1;
        int current_distance = 0;
        while(!queue.empty()) {
            int size = queue.size();
            if(current_distance++ == k) break;
            for(int j = 0; j < size; j++) {
                TreeNode* current = queue.front();
                queue.pop();
                if(current->left != NULL && visited_node.find(current->left) == visited_node.end()) {
                    queue.push(current->left);
                    visited_node[current->left] = 1;
                }
                if(current->right != NULL && visited_node.find(current->right) == visited_node.end()) {
                    queue.push(current->right);
                    visited_node[current->right] = 1;
                }
                if(parent[current] && !visited_node[parent[current]]) {
                    queue.push(parent[current]);
                    visited_node[parent[current]] = 1;
                }
            }
        }

        vector<int> distanceK_nodes;
        while(!queue.empty()) {
            distanceK_nodes.push_back(queue.front()->val);
            queue.pop();
        }
        return distanceK_nodes;
    }
};