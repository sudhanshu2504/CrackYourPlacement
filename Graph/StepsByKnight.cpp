class Solution{
    public:
    
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
    {
        int delrow[]={-2,-2,-1,-1,1,1,2,2};
        int delcol[]={-1,1,-2,2,-2,2,1,-1};
        vector<vector<int>>vis(N,vector<int>(N,0));
        queue<pair<pair<int,int>,int>>q;
        vis[kp[0]-1][kp[1]-1]=1;
        q.push({{kp[0]-1,kp[1]-1},0});
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            q.pop();
            if(row==tp[0]-1 and col==tp[1]-1)return d;
            for(int i=0;i<8;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 and nrow<N and ncol>=0 and ncol<N and 
                !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return -1;
    }
};