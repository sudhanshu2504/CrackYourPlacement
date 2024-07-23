class Solution {
  public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index ; i<nums.size() ; i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        solve(arr,ans,0);
        
        sort(ans.begin(),ans.end());
        
        for(int i=0 ; i<ans.size()-1 ; i++){
            if(ans[i] == ans[i+1]){
                ans.erase(ans.begin()+i);
                i--;
            }
        }
        
        return ans;
    }
};