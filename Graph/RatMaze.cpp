class Solution {
  public:
    vector<string> ans;
    void solve(vector<vector<int>>& mat, int i, int j, string s, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=mat.size() || j>=mat.size() || visited[i][j] || mat[i][j] == 0){
            return;
        }
        if(i == mat.size()-1 && j == mat.size()-1){
            ans.push_back(s);
            return;
        }
        visited[i][j] = true;
        
        solve(mat,i+1,j,s+'D',visited);
        solve(mat,i-1,j,s+'U',visited);
        solve(mat,i,j+1,s+'R',visited);
        solve(mat,i,j-1,s+'L',visited);
    
        visited[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<vector<bool>> visited(mat.size(),vector<bool>(mat.size(),false));
        if(mat[0][0]){
            solve(mat,0,0,"",visited);
        }
        
        return ans;
    }
};