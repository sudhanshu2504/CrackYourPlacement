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
    bool check(TreeNode* l , TreeNode* r){
        if(!l && !r){
            return 1;
        }
        if(!l || !r){
            return 0;
        }
        return (l->val == r->val && check(l->left, r->right) && check(r->left , l->right));
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left , root->right);
    }
};