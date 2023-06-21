class Solution {
public:
  void create_tree(node* root0, vector<int> &vec){
          //Your code goes here
          int n = vec.size();
          queue<node*> q;
          q.push(root0); // 0

          for(int i = 0;i<n/2;i++) {
              node *root = q.front();
              q.pop();

              int left = 2*i + 1; // 1 5 7
              int right = 2*i + 2; // 2 6 8
              root->left = newNode(vec[left]);
              root->right = newNode(vec[right]);

              q.push(root->left);
              q.push(root->right);
          }
      }
};
