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


// Iterative traversal using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        stack<TreeNode*> st;
        st.push(root); // 3
        while(!st.empty()) {
            TreeNode* node = st.top(); // 1 2 3
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left); // 3
            
            preorder.push_back(node->val); // 1 2
        }
        return preorder;
    }
};
