/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* construct(queue<string> &q){
        string node = q.front();q.pop();
        if(node == "x"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = construct(q);
        root->right = construct(q);

        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "x,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0 ; i<data.length() ; i++){
            if(data[i] == ','){
                q.push(s);
                s="";
            }else{ 
                s += data[i];
            }
        }
        if(s.size() != 0){
            q.push(s);
        }
        TreeNode* ans = construct(q);
        return ans;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));