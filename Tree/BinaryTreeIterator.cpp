/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    deque<int> node;
    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        traversal(root->left);
        node.push_back(root->val);
        traversal(root->right);
    }
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    
    int next() {
        int nextNode = node.front();node.pop_front();
        return nextNode;
    }
    
    bool hasNext() {
        return !node.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */