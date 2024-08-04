class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visit(V,false);
        queue<int>bfs;
        bfs.push(0);
        visit[0] = true;
        while(!bfs.empty()){
            int current = bfs.front();bfs.pop();
            ans.push_back(current);
            for(auto &i:adj[current]){
                if(!visit[i]){
                    bfs.push(i);
                    visit[i] = true;
                }
            }
        }
        return ans;
    }
};