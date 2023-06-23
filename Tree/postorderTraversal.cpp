class Solution {
private:
    void getAllValuesInPostorder(TreeNode* root, vector<int> &postorder) {
        if(root == NULL) return;

        getAllValuesInPostorder(root->left, postorder);
        getAllValuesInPostorder(root->right, postorder);
        postorder.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        getAllValuesInPostorder(root, postorder);
        return postorder;
    }
};
