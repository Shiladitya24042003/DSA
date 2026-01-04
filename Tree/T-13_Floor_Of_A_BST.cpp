/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int floor(Node* root, int x) {
        int ceil = -1;
        Node* curr = root;
        while(curr != NULL) {
            if(curr->data == x) return x;
            if(curr->data > x) {
                curr = curr->left;
            }
            else {
                ceil = curr->data;
                curr = curr->right;
            }
        }
        return ceil;
    }
};
