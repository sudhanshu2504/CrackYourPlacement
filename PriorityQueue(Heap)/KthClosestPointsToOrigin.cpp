class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(int i=0 ; i<points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];

            int distance = (x*x) + (y*y);

            if(!pq.empty() && distance == pq.top().first && pq.size() >= k){
               pq.pop();
            }
            pq.push({distance,{x,y}});

            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};