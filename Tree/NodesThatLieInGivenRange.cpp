class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      int ans = 0;
      stack<Node*> dfs;
      dfs.push(root);
      while(!dfs.empty()){
          Node* current = dfs.top();dfs.pop();
          if(current->data>=l && current->data<=h){
              ans++;
          }
          if(current->left){
              dfs.push(current->left);
          }
          if(current->right){
              dfs.push(current->right);
          }
      }
      return ans;
    }
};
