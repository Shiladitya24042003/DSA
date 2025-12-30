class Solution {
public:
    bool getPath(TreeNode* root, vector<int> &arr, int x) {
        if(!root)
            return false;
        arr.push_back(root->val);
        
        if(root->val == x)
            return true;

        if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;
    }
public:
    vector<int> pathInATree(TreeNode* root, int x) {
        vector<int> arr;
        if(root == NULL)
            return {-1};
        if(getPath(root, arr, x))
            return arr;
        return {-1};
    }
}