class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> visit(nums.size(),false);
        for(int i=0 ; i<nums.size() ; i++){
            if(visit[nums[i]]){
                return nums[i];
            }else{
                visit[nums[i]] = true;
            }
        }
        return -1;
    }
};