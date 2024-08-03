/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        Node* ans = root;
        queue<Node*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0 ; i<size ; i++){
                Node* temp = bfs.front();
                bfs.pop();
                if(temp->left != NULL){
                    bfs.push(temp->left);
                }
                if(temp->right != NULL){
                    bfs.push(temp->right);
                }
                Node* nextNode = bfs.front();
                temp->next = nextNode;
                if(i == size-1){
                    temp->next = NULL;
                }
            }
        }
        return ans;
    }
};