class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        queue<pair<int,pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,{0,src}});

        for(int i=0 ; i<flights.size() ; i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        while(!pq.empty()){
            int stop = pq.front().first;
            int distance = pq.front().second.first;
            int node = pq.front().second.second;
            pq.pop();

            for(auto &i : adj[node]){
                int newDist = distance + i.second;
                int newNode = i.first;

                if(newDist < dist[newNode] && stop <= k){
                    dist[newNode] = newDist;
                    pq.push({stop+1,{newDist,newNode}});
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};