class Solution {
public:
    int uniquePaths(int m, int n) {
        int right = n-1;
        int down = m-1;
        int total = right + down;
        long ans = 1;
        int k = min(down,right);
        for(int i=1 ; i<=k ;i++){
            ans = ans * (total-k+i)/i;
        }
        return (int)ans;
    }
};