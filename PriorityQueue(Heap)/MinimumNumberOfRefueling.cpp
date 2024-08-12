class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i = 0;
        int ans = 0;
        int current = startFuel;
        
        priority_queue<int> pq;

        while(current < target){
            while(i<stations.size() && current>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            current += pq.top();pq.pop();
            ans++;
        }
        return ans;
    }
};