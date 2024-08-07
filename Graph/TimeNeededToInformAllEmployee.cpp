class Solution {
public:
    int dfs(int emp, vector<vector<int>> &adj, vector<int> & informTime){
        int timeNeeded = 0;
        for(auto i:adj[emp]){
            timeNeeded = max(timeNeeded,dfs(i,adj,informTime));
        }
        return timeNeeded + informTime[emp];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n ; i++){
            if(i != headID){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime);
    }
};