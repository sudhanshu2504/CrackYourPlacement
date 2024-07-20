class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        vector<int> data(nums.size()+1,0);
        for(int i=0 ; i<nums.size() ; i++){
            if(data[nums[i]] != 0){
                ans.push_back(nums[i]);
            }else{
                data[nums[i]]++;
            }
        }
        return ans;
    }
};