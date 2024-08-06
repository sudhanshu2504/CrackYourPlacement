class Solution {
public:
    void dfs(vector<bool> &visited, int node ,vector<vector<int>>&adj){
        if(visited[node]) {
            return;
        }
        visited[node] = true;
        for(int i=0 ; i<adj[node].size() ; i++){
            if(!visited[adj[node][i]]){
                dfs(visited,adj[node][i],adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int connection = c.size();
        if(connection < n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(int i=0 ; i<c.size() ; i++){
            int s = c[i][0];
            int e = c[i][1];
            // cout<<"{"<<s<<","<<e<<"}"<<endl;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        int component = 0;
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                dfs(visited,i,adj);
                component++;
            }
        }
        return component-1;
    }
};