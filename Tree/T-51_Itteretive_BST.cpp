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
class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAllLeft(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 /**
  * We are using the Inorder Traversal technique to traverse. 
  When erver we are calling the next() we are just pushing all the left 
  values to that node->right including node->right
  Take for Example the follwinh test case
                           7
                          / \
                         /   \
                        /     \
                       /       \
                      3         10
                     / \       /
                    2   6     9
                   /   /     /
                  1   5     8
                     /
                    4 
    first got 7 then push all the left nodes including 7.
    now wehn the next() is called just orint the top of stack as it 
    would be the guy in inorder traversal and mive to right if exists and push all its 
    left nodes including that right node also
    
    Just try to implement the itterative inorder traversal. That's it !!/