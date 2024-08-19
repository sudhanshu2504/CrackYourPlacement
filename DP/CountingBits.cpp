class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n+1,-1);
        dp[i] = 0;
        dp[i] = 1;
        
        for(int i=0 ; i<n+1 ; i++){
            dp[i] = dp[i/2];
            if(i%2 != 0){
                dp[i]++;
            }
        }
        return dp;
    }
};