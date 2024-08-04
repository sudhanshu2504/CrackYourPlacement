class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited , int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || visited[i][j] != -1 || grid[i][j] == '0'){
            return;
        }
        visited[i][j] = 1;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(visited[i][j] == -1 && grid[i][j] == '1'){
                    dfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};