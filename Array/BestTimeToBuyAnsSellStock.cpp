class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lowest = prices[0];
        for(int j=1 ; j<prices.size() ; j++){
            ans = max(ans,prices[j]-lowest);
            lowest = min(lowest,prices[j]);
        }
        return ans;
    }
};