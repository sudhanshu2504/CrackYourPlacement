void dfs(int node, vector<vector<int>>& adj, stack<int>&st, vector<bool>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]) dfs(it, adj, st, vis);
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>&adj, vector<bool>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]) dfs2(it, adj, vis);
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool>vis(V, 0);
        stack<int>st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, adj, st, vis);
        }
        
        vector<vector<int>>adjRev(V);
        for(int i=0; i<V; i++){
            for(auto &it:adj[i]){
                adjRev[it].push_back(i);
            }
        }
        
        int cnt=0;
        
        vis=vector<bool>(V, 0);
        
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node, adjRev, vis);
                cnt++;
            }
        }
        return cnt;
    }