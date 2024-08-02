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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<int> level;
    vector<vector<int>> ans;

    if(root == NULL){
        return {};
    }

    queue<TreeNode*> current;

    current.push(root);
    while(!current.empty() ){
    queue<TreeNode*> nextLevel;
        while(!current.empty()){
            TreeNode*  node = current.front();
            current.pop();
            if(node){
                if(node->left){
                    nextLevel.push(node->left);
                }
                if(node->right){
                    nextLevel.push(node->right);
                }
                level.push_back(node->val);
            }
        }
        ans.push_back(level);
        level.clear();
        current = nextLevel;
    
    }

    return ans; 
    }
};