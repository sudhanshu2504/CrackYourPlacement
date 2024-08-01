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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        stack<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            TreeNode* node = bfs.top();bfs.pop();
            if(node->left){
                bfs.push(node->left);
                if(node->left->left == NULL && node->left->right == NULL){
                    ans += node->left->val;
                }
            }
            if(node->right){
                bfs.push(node->right);
            }
        }
        return ans;
    }
};