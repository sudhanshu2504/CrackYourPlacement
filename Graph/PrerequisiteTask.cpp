class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> indegree(N,0);
	    queue<int>q;
	    int ans = 0;
	    
	    for(auto it:prerequisites)
	        adj[it.first].push_back(it.second);
	       
	    for(int i = 0; i < N; i++){
	        for(auto it:adj[i])
	            indegree[it]++;
	    }
	    
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
    	    q.pop();
	        ans++;
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it);
	        }
	    }
	    
	    if(ans == N) return true;
	    return false;
	}
};