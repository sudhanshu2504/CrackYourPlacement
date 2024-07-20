class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0 && ans<nums.size()-1 && ans<=i){
                return false;
            }
            if(i+nums[i] > ans){
                ans = nums[i]+i;
            }
        }
        return ans>=nums.size()-1;
    }
};