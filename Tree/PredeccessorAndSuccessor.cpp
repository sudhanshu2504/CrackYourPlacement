class Solution
{
    public:
    void inOrder(Node* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->key);
        inOrder(root->right,ans);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        
        vector<int> data;
        inOrder(root,data);
        
        for(int i=0 ; i<data.size() ; i++){
            if(data[i] < key){
                pre = new Node(data[i]);
            }
            if(data[i] > key){
                suc = new Node(data[i]);
                break;
            }
        }
        
    }
};