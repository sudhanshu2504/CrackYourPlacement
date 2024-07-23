class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // yi-xi,xi;
        int ans = INT_MIN;
        int sum;

        pq.push({points[0][1]-points[0][0],points[0][0]});

        for(int i=1 ; i<points.size() ; i++){
            sum = points[i][0] + points[i][1]; //yi + xi

            while(!pq.empty() && points[i][0]-pq.top().second>k){
                pq.pop();
            }
            if(!pq.empty()){
                ans = max(ans, sum + pq.top().first); // sum (yi+xi) + pq.top.first (yj-xj) = yj+yi + |xi-xj|
            }
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }   
};