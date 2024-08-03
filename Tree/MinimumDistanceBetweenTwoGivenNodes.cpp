class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root, int a,int b){
        if(root == NULL){
            return NULL;
        }
        if(root->data == a || root->data == b){
            return root;
        }
        auto leftSide = lca(root->left,a,b);
        auto rightSide = lca(root->right,a,b);
        
        if(leftSide && rightSide){
            return root;
        }
        if(leftSide){
            return leftSide;
        }
        if(rightSide){
            return rightSide;
        }
    }
    
    int getLength(Node* root,int a, int length){
        if(root == NULL){
            return -1;
        }
        if(root->data == a){
            return length;
        }
        
        int leftSide = getLength(root->left,a,length+1);
        if(leftSide != -1){
            return leftSide;
        }
         
        return getLength(root->right,a,length+1);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* ca = lca(root,a,b);
        
        int l1 = getLength(ca,a,0);
        int l2 = getLength(ca,b,0);
        
        return l1+l2;
    }
};