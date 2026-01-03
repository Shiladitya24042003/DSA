/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void inorder(Node* root, vector<int> &ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        inorder(root->left, ans);
        inorder(root->right, ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        if(root->left == NULL && root->right == NULL) return {root->data};
        ans.push_back(root->data);
        //left boundary
        Node* curr = root->left;
        while(curr) {
            if(curr->left || curr->right)
                ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        
        //leaf Nodes
        inorder(root, ans);
        
        // Right boundary in reversed order
        vector<int> temp;
        curr = root->right;
        while(curr) {
            if(curr->left || curr->right)
                temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i = temp.size()-1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
        return ans;
        
    }
};


/**
Suppose for example 
        1
         \
          2
         / \
        3   4
        
        
Then the output is 1, 3, 4, 2
/