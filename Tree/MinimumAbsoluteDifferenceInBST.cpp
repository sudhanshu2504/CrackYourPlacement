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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> values;
        stack<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()){
            TreeNode* node = bfs.top();bfs.pop();
            values.push_back(node->val);
            if(node->left){
                bfs.push(node->left);
            }

            if(node->right){
                bfs.push(node->right);
            }
        }
        sort(values.begin(),values.end());
        for(int i=0 ; i<values.size()-1 ; i++){
            ans = min(ans,abs(values[i]-values[i+1]));
        }
        return ans;
    }
};