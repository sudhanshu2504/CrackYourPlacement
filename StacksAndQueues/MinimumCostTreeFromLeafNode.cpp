class Solution {
public:
    int findMax(vector<int>& arr, int left, int right) {
        int maxi = 0;
        for(int i = left; i <= right; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int solve(vector<int>& arr, int left, int right, vector<vector<int>> &dp) {
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for(int i = left; i < right; i++) {
            ans = min(ans, (findMax(arr, left, i) * findMax(arr, i + 1, right)) + (solve(arr, left, i, dp) + solve(arr, i + 1, right, dp)));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solve(arr, 0, n - 1, dp);
        return ans;
    }
};