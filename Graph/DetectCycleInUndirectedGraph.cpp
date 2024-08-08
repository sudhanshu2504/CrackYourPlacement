class Solution {
  public:
    bool check(int source, vector<int> adj[], vector<bool> visited){
        visited[source] = true;
        queue<pair<int,int>> q; // node,parent
        q.push({source,-1});
        
        while(!q.empty()){
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto &i:adj[current]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push({i,current});
                }else if(i != parent){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        
        for(int i=0 ; i<V ; i++){
            if(check(i,adj,visited)){
                return true;
            }
        }
        
        return false;
    }
};