class Solution {
public:
    void solve(vector<int>&nums, vector<vector<int>> &ans ,vector<int> &temp,int i){
        ans.push_back(temp);
        
        for(int j=i ; j<nums.size() ; j++){
            temp.push_back(nums[j]);
            solve(nums,ans,temp,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    // ans.push_back({});
    vector<int> temp;
    solve(nums,ans,temp,0);
    return ans;
    }
};