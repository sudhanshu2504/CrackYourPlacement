class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int total = 0, sum = 0;
        for(int i=0 ; i<gas.size() ; i++){
            sum += gas[i] - cost[i];
            if(sum<0){
                total += sum;
                sum=0;
                ans = i+1;
            }
        }
        total+=sum;
        if(total>=0){
            return ans;
        }
        return -1;
    }
};