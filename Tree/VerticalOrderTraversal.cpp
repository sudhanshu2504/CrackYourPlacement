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
    map<int,vector<pair<int,int>>> verticalOrder;

    void solve(TreeNode* root, int h, int v){
        if(root == NULL){
            return ;
        }
        verticalOrder[v].push_back({h,root->val});
        cout<<"{"<<h<<","<<root->val<<"}"<<endl;
        solve(root->left,h+1,v-1);
        solve(root->right,h+1,v+1);  
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto& i:verticalOrder){
            sort(i.second.begin(),i.second.end());
            vector<int> temp;
            for(auto &j : i.second){
                temp.push_back(j.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};