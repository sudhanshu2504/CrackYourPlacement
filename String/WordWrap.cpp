class Solution {
public:
    int solve(vector<int>& nums, int i,int j,int k, vector<int>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        int occupied = 0;
        
        for(int index=i ; index<=j ; index++){
            occupied += nums[index];
            if(occupied<=k && index == j){
                return dp[i] = 0;
            }
            if(occupied <= k){
                int extra = (k-occupied)*(k-occupied);
                int cost = extra + solve(nums,index+1,j,k,dp);
                ans = min(ans,cost);
                occupied++;
                }
        }
        dp[i] = ans;
        return ans;
    }
    int solveWordWrap(vector<int>nums, int k) { 
        // Code here
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n-1,k,dp);
    } 
};