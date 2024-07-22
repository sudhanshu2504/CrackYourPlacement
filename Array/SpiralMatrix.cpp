class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0;

        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),false));
        string d = "right"; // "down","left","up";
        vector<int> ans;
        
        while(i<matrix.size() && j<matrix[0].size() && !visited[i][j]){
            cout<<i<<","<<j<<endl;
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            if(d == "right"){
                if(j+1 < matrix[0].size() && !visited[i][j+1]){
                    j++;
                }else{
                    d = "down";
                    i++;
                }
            }
            else if(d == "down"){
                if(i+1 < matrix.size() && !visited[i+1][j]){
                    i++;
                }else{
                    d = "left";
                    j--;
                }
            }
            else if(d == "left"){
                if(j-1 >= 0 && !visited[i][j-1]){
                    j--;
                }else{
                    d = "up";
                    i--;
                }
            }
            else if(d == "up"){
                if(i-1 >= 0 && !visited[i-1][j]){
                    i--;
                }else{
                    d = "right";
                    j++;
                }
            }
        }
        return ans;
    }
};