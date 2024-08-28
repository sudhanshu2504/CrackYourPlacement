class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int ans = 0; 
    vector<int> dp(nums.size()+1,0);
    for(int i=0 ; i<nums.size() ; i++){
        int temp = 0;
        for(int j=i ; j>=0 ; j--){
            if(nums[i]>nums[j]){
                temp = max(temp,dp[j]);
            }
        }
        dp[i] = temp+1;
    }
    for(int i=0 ; i <dp.size() ; i++){
        ans = max(ans,dp[i]);
    }
    return ans;
    }
};