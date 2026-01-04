class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        Node* curr = root;
        while(curr != NULL) {
            if(curr->data == x) return x;
            if(curr->data > x) {
                ceil = curr->data;
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return ceil;
    }
};
