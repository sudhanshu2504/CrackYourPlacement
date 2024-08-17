class Solution {
public:
    set<pair<int,int>> ans;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) dfs(i,node,adj,vis);
            else if(parent!=i){
                ans.insert({node,i});
                ans.insert({i,node});
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n+1];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int a=0,b=0;
        for(int i=1 ; i<=n ; i++){
            vector<int> vis(n+1,0);
            dfs(i,-1,adj,vis);

            for(int i=n-1 ; i>=0 ; i--){
                if(ans.find({edges[i][0],edges[i][1]})!=ans.end()){
                    a = edges[i][0];
                    b = edges[i][1];
                    break;
                }
            }
        }
        return {a,b};
    }
};