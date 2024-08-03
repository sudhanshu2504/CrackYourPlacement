class Solution
{
    public: 
    void inOrder(Node* root,vector<int> &data){
        if(root == NULL){
            return;
        }
        
        inOrder(root->left,data);
        data.push_back(root->data);
        inOrder(root->right,data);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        vector<int> data;
        inOrder(root,data);
        
        if(data.size() == 0){
            return NULL;
        }
        
        Node* ans = new Node(data[0]);
        Node* temp = ans;
        
        
        for(int i=1 ; i<data.size() ; i++){
            Node* nextNode = new Node(data[i]);
            temp->right = nextNode;
            nextNode->left = temp;
            temp = temp->right;
        }
        return ans;
    }
};