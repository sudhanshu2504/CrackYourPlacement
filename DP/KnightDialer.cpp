class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9+7;
        vector<vector<int>> reach = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(n+1,vector<int>(10,0));
        for(int i=0 ; i<10 ; i++){
            dp[0][i] = 1;
        }
        for(int i=1 ; i<n ;i++){
            for(int j=0 ; j<10 ; j++){
                for(auto next:reach[j]){
                    dp[i][j] =( dp[i][j] + dp[i-1][next])%mod;
                }
            }
        }
        long ans = 0;
        for(int i=0 ; i<10 ; i++){
            ans = (ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};