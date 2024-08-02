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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> bfs;
        bfs.push(root);
        TreeNode* temp;

        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0 ; i<size ; i++){
                temp = bfs.front();
                bfs.pop();
                if(temp->left){
                    bfs.push(temp->left);
                }
                if(temp->right){
                    bfs.push(temp->right);
                }
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};