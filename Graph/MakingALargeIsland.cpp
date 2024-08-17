class Solution {
public:
    bool isValid(int row,int col, vector<vector<int>>&grid){
        return row>=0 && col>=0 && row<grid.size() && col<grid[0].size();
    }
    int dfs(int i, int j, vector<vector<int>> &grid, int & key,int row,int col){      
        if(i < 0 || j < 0 || i >= row || j >= col)
            return 0;
        
        if(grid[i][j] == 0 || grid[i][j] ==  key)
            return 0;
        
        grid[i][j] = key;
        
        return 1 
        + dfs(i + 1, j, grid,key,row,col)
        + dfs(i - 1, j , grid,key,row,col)
        + dfs(i, j + 1, grid,key,row,col)
        + dfs(i, j - 1, grid,key,row,col);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int key = 101;
        map<int,int> mp; // key,size
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    int size = dfs(i,j,grid,key,grid.size(),grid[0].size());
                    mp[key] = size;
                    key++;
                }
            }
        }
        int ans = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==0){
                    set<int> st;
                    vector<int> dr = {-1,0,1,0};
                    vector<int> dc = {0,1,0,-1};
                    for(int index=0 ; index<4 ; index++){
                        int nr = i + dr[index];
                        int nc = j + dc[index];
                        if(isValid(nr,nc,grid)){
                            st.insert(grid[nr][nc]);
                        }
                    }
                    
                    int sum = 1;
                    for(auto i:st)
                        sum += mp[i];
                    
                    ans = max(ans, sum);
                    
                }
            }
        }
        return ans==0 ? (grid.size()*grid[0].size()) : ans; 
    }
};