class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid.size(),0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({grid[0][0],{0,0}});
        visited[0][0]= 1;

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            int d = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if(r == grid.size()-1 && c == grid.size()-1){
                return d;
            }
            for(int i=0 ; i<4 ; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid.size() && visited[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    pq.push({max(d,grid[nr][nc]),{nr,nc}});
                }
            }
        }
        return -1;
    }
};