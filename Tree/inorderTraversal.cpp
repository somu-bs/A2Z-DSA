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


// Itetative traversal using stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> sk;
        TreeNode* node = root;
        while(true) {
            if(node != NULL) {
                sk.push(node);
                node = node->left;
            }
            else {
                if(sk.empty()) break;
                node = sk.top();
                sk.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
