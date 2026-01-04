/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
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
            if(mpp.find(line) == mpp.end())
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
/**
    Take for example this test case
                   1
                  / \
                 2   3
                   /   \
                  4     5
                 /
                6
        
    The output will be [6, 2, 1, 3, 5]
    Had You done the itterative approach of going left-left-left and 
    right-right-right this would definitely fail 
    and would give the answer as [2, 1, 3, 5]
        
    So a level Order traversal with vertical approach is required !!

*/