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
    int maxDepth(TreeNode* root) {
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
};