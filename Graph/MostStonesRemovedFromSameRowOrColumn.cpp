class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<bool> & visited, int i){
        visited[i] = true;
        for(int j=0 ; j<stones.size() ; j++){
            if(!visited[j]){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    dfs(stones,visited,j);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
       int n = stones.size(); 
       vector<bool> visited(n,false);
        
        int notRemove = 0;

        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                dfs(stones,visited,i);
                notRemove++;
            }
        }
        return n - notRemove;
    }
};