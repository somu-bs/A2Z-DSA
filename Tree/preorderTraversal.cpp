class Solution {
private:
    void getValuesInPreorder(TreeNode *root, vector<int> &preorder) {
        if(root == NULL) return;
        
        preorder.push_back(root->val);
        getValuesInPreorder(root->left, preorder);
        getValuesInPreorder(root->right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        getValuesInPreorder(root, preorder);
        return preorder;
    }
};
