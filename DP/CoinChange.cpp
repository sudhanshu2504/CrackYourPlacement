class Solution {
public:
    int solve(vector<int>&coins, int amount, int index,vector<vector<int>> &dp){
        if(index>=coins.size() || amount<=0){
            return (amount == 0)?0:INT_MAX-1;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int ans = -1;
        if(coins[index]>amount){
            ans = solve(coins,amount,index+1,dp);
        }else{
            int take = 1 + solve(coins,amount-coins[index],index,dp);
            int notTake = 0 + solve(coins,amount,index+1,dp);
            ans = min(take,notTake);
        }
        return dp[index][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};