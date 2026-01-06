/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        Node* successor = NULL;
        Node* predecessor = NULL;
        Node* curr = root;
        while(curr != NULL) {
            if(key >= curr->data) {
                curr = curr->right;
            }
            else {
                successor = curr;
                curr = curr->left;
            }
        }
        curr = root;
        while(curr != NULL) {
            if(key > curr->data) {
                predecessor = curr;
                curr = curr->right;
            }
            else {
                
                curr = curr->left;
            }
        }
        ans.push_back(predecessor);
        ans.push_back(successor);
        
        return ans;
    }
};