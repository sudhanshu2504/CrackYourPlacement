class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid ,vector<vector<int>>& dp){
        if(i == grid.size() - 1 and j == grid[0].size() - 1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(i + 1 < grid.size()){
            ans = min(ans, grid[i][j] + solve(i + 1, j, grid,dp));
        }
        if(j + 1 < grid[0].size()){
            ans = min(ans, grid[i][j] + solve(i, j + 1, grid,dp));
        }
        return dp[i][j] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0, 0, grid,dp);
    }
};