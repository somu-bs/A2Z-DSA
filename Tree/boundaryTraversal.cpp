// TC - O(Left H) + O(right H) + O(N)
// SC - O(N)


#include<bits/stdc++.h>
using namespace std;

bool isLeaf(TreeNode<int>* root) {
    return (!root->left) && (!root->right);
}

void leftBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* temp = root->left;
    while(temp) {
        if(!isLeaf(temp)) ans.push_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp = temp->right;
    }
}

void rightBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* temp = root->right;
    vector<int> v;
    while(temp) {
        if(!isLeaf(temp)) v.push_back(temp->data);
        if(temp->right) temp = temp->right;
        else temp = temp->left;
    }
    for(int i = v.size()-1;i>=0;i--) {
        ans.push_back(v[i]);
    }

}

void getLeaves(TreeNode<int>* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) getLeaves(root->left, ans);
    if(root->right) getLeaves(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root, ans);
    getLeaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}
