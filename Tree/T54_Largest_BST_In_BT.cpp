/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue {
  public:
    int max;
    int min;
    int size;
    NodeValue(int max, int min, int size) {
        this->max = max;
        this->min = min,
        this->size = size;
    }
};
class Solution {
  private:
    NodeValue helper(Node* root) {
        if (!root)
            return NodeValue(INT_MIN, INT_MAX, 0);
    
        auto left = helper(root->left);
        auto right = helper(root->right);
    
        if (left.max < root->data && root->data < right.min) {
            return NodeValue(max(root->data, right.max), min(root->data, left.min), left.size + right.size + 1);
        }
    
        return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));
    }

  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return helper(root).size;
    }
};

/**
Just run your code on this test case once
                  10
                 /  \
                5    15
                    /  \
                   6    X
                   
                The largest BST size is 3 which is 
                10
               /  \
              5    15
              
    So if u are thinking this:
        assuming that a subtree is a BST if its root value lies between its immediate 
        left and right child values, and then summing their sizes.
    Then U are absolutely WRONG !!
    Just run the above test case. You will get it.
*/