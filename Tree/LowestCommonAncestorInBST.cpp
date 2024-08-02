/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p == root || q == root){
            return root;
        }
        TreeNode* leftSideCheck = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSideCheck = lowestCommonAncestor(root->right,p,q);

        if(leftSideCheck != NULL && rightSideCheck != NULL){
            return root;
        }
        else if(leftSideCheck == NULL){
            return rightSideCheck;
        }
        else{
            return leftSideCheck;
        }
        return NULL;
    }
};