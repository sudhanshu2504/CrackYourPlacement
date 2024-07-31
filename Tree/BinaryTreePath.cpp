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
    void solve(vector<string>& ans,stack<TreeNode*> &st , string temp){
        TreeNode* root = st.top();
        st.pop();
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        if(root->left){
            st.push(root->left);
            solve(ans,st, temp + "->" + to_string(root->left->val));
        }
        if(root->right){
            st.push(root->right);
            solve(ans,st, temp + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> st;
        vector<string> ans;

        st.push(root);
        solve(ans,st,to_string(root->val));
        return ans;
    }
};