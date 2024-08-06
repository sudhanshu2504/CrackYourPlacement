class NodeValue{
    public:
        int maxi, mini, size;
        NodeValue(int size,int maxi, int mini){
            this->size = size;
            this->maxi = maxi;
            this->mini = mini;
        }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue helper(Node* root){
        if(root == NULL){
            return NodeValue(0,INT_MIN,INT_MAX);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if(left.maxi < root->data && right.mini>root->data){
            return NodeValue(1+left.size+right.size, max(root->data,right.maxi), min(root->data,left.mini));
        }
        return NodeValue(max(left.size,right.size),INT_MAX,INT_MIN);
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	return helper(root).size;
    }
};