class Solution {
private:
    void getAllValuesInInorder(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) return;

        getAllValuesInInorder(root->left, inorder);
        inorder.push_back(root->val);
        getAllValuesInInorder(root->right, inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        getAllValuesInInorder(root, inorder);
        return inorder;
    }
};
