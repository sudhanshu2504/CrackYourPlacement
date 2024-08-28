class Solution {
public:
    map<int,int> m;
    bool solve(int i, int k, vector<int>& stones,vector<vector<int>>& dp) {
        if (i == stones.size() - 1) {
            return true;
        }
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        bool before = false;
        bool current = false;
        bool after = false;

        if (m.find(stones[i] + k) != m.end()) {
            before = solve(m[stones[i] + k], k, stones,dp);
        }
        if (k > 1 && m.find(stones[i] + k - 1) != m.end()) {
            current = solve(m[stones[i] + k - 1], k - 1, stones,dp);
        }
        if (m.find(stones[i] + k + 1) != m.end()) {
            after = solve(m[stones[i] + k + 1], k + 1, stones,dp);
        }

        dp[i][k] = before || current || after;
        return dp[i][k];
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        if (stones[1] - stones[0] != 1) {
            return false;
        }
        for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }
        return solve(1,1,stones,dp);
    }
};