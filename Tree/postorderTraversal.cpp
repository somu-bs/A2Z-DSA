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


// Iterative traversal using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node = st1.top(); // 
            st1.pop();
            if(node->left) st1.push(node->left); // 3
            if(node->right) st1.push(node->right);
            st2.push(node); // 1 2 3
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};


// Iterative traversal using 1 stack
// TC - O(2N)   SC - O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> st; // 1 2 3
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right; // 2
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    } 
                }
                else {
                    curr = temp; // 2
                }
            }
        }
        return postorder;
    }
};
