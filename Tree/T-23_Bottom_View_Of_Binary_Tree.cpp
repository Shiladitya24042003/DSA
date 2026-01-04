/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        if(root->left == NULL && root->right == NULL) return {root->data};
        
        map<int, int> mpp;
        queue<pair<Node*, int>> queue;
        queue.push({root, 0});
        
        while(!queue.empty()) {
            auto it = queue.front();
            Node* node = it.first;
            int line = it.second;
            queue.pop();
            
            mpp[line] = node->data;
            if(node->left) {
                queue.push({node->left, line-1});
            }
            if(node->right) {
                queue.push({node->right, line+1});
            }
        }
        
        for(auto it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};