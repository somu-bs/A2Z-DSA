class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> allLevel;
        if(root == NULL) return allLevel;
        queue<TreeNode*> q;
        q.push(root); // 3
        while(!q.empty()) {
            int sizeOfQueue = q.size();
            vector<int> eachLevel;
            for(int i = 0;i<sizeOfQueue;i++) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                eachLevel.push_back(node->val);
            }
            allLevel.push_back(eachLevel);
        }
        return allLevel;
    }
};
