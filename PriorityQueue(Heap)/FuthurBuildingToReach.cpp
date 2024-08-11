class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int used = 0;
        for(int i=0 ; i<h.size()-1 ; i++){
            if(h[i+1]>h[i]){
                pq.push(h[i+1]-h[i]);
            }
            if(pq.size() > l){
                used += pq.top();
                pq.pop();
            }
            if(used > b){
                return i;
            }
        }
        return h.size()-1;
    }
};