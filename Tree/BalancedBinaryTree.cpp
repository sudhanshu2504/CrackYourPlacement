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
class Solution {
public:
    int get(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int ans = 0;

        queue<TreeNode*> level;
        level.push(root);

        while(!level.empty()){
            int size = level.size();
            if(size != 0){
                ans++;
            }
            while(size--){
                TreeNode* temp = level.front();
                level.pop();

                if(temp->left != NULL){
                    level.push(temp->left);
                }          
                if(temp->right != NULL){
                    level.push(temp->right);
                }
            }
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        int left = 0;
        int right = 0;
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        if(root->left != NULL){
            left = get(root->left);
        }
        if(root->right != NULL){
            right = get(root->right);
        }
        cout<<"Left : "<<left;
        cout<<"Right : "<<right;
        return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};