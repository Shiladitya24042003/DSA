/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    Node* mark_parent(Node* root, unordered_map<Node*, Node*> &parent, int target) {
        queue<Node*> q;
        q.push(root);
        Node* target_node = NULL;

        while(!q.empty()) {
            Node* current = q.front(); q.pop();
            if(current->data == target) target_node = current;

            if(current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
        return target_node;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;
        Node* target_node = mark_parent(root, parent, target);

        unordered_map<Node*, int> visited_node;
        queue<Node*> queue;
        queue.push(target_node);
        visited_node[target_node] = 1;
        int time = 0; 
        while(!queue.empty()) {
            int size = queue.size();
            time++;
            for(int j = 0; j < size; j++) {
                Node* current = queue.front();
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
        return time-1;
    }
};