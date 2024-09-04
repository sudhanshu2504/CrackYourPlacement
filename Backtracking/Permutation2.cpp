class Solution {
public:
    void solve(set<vector<int>> &ans, vector<int>&nums,int index){
        if(index == nums.size()){
            return;
        }
        ans.insert(nums);
        for(int i=index ; i<nums.size() ; i++){
            swap(nums[i],nums[index]);
            solve(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> storage;
        solve(storage,nums,0);
        vector<vector<int>> ans;
        for(auto&i : storage){
            ans.push_back(i);
        }
        return ans;
    }
};