class Solution {
  public:
    Node* build(int pre[] ,int &size,int &index ,int i, int j){
        if(index>=size){
            return NULL;
        }
        if(i>pre[index] || j<pre[index]){
            return NULL;
        }
        Node* root = newNode(pre[index++]);
        root->left = build(pre,size,index,i,root->data);
        root->right = build(pre,size,index,root->data,j);
        
        return root;
    }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        if(size == 0){
            return NULL;
        }
        int i=0;
        return build(pre,size,i,0,INT_MAX);
    }
};