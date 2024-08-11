class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int total = 0;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                pq.push(matrix[i][j]);
                total++;
            }
        }
        total = total-k+1;
        while(total--){
            if(total==0){
                return pq.top();
            }
            pq.pop();
        }
        return -1;
    }
};