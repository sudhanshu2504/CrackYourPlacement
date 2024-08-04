class Solution {
private:
    void solveForDfs(int node, vector<int> &ans, vector<bool> &visited, vector<int> adj[] ){
        ans.push_back(node);
        if(visited[0]!=true){
          visited[0]= true;
           
        }
        for(auto i: adj[node]){
            if(!visited[i]){
                visited[i]= true;
                solveForDfs(i, ans, visited, adj);
            }
        }
    }
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V,false);
        
        solveForDfs(0, ans, visited, adj);
        return ans;
        
        
    }
};