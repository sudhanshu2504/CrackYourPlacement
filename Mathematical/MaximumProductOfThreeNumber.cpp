class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-3;
        int j=nums.size()-2;
        int k=nums.size()-1;
        
        int ans = nums[i]*nums[j]*nums[k];
        ans = max(ans,nums[0]*nums[1]*nums[k]);
        return ans;
    }
};