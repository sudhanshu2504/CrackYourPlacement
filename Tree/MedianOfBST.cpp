float findMedian(struct Node *root)
{
      //Code here
      vector<int> values;
      stack<struct Node*> bfs;
      bfs.push(root);
      while(!bfs.empty()){
          struct Node* node = bfs.top();bfs.pop();
          values.push_back(node->data);
          if(node->left){
              bfs.push(node->left);
          }
          if(node->right){
              bfs.push(node->right);
          }
      }
      float ans = 0;
      sort(values.begin(),values.end());
      int mid = values.size()/2;
      if(values.size()%2 == 0){
          ans = (values[mid] + values[mid-1])/2.0;
      }else{
          ans = values[mid];
      }
      return ans;
}