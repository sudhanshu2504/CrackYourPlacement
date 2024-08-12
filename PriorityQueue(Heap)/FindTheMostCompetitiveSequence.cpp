class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> extra;
        for(int i=0 ; i<nums.size() ; i++){
            while(!extra.empty() && extra.back()>nums[i] && extra.size()+nums.size()-i>k){
                extra.pop_back();
            }
            extra.push_back(nums[i]);
            if(extra.size() == k){
                ans = extra;
            }
        }
        return ans;
    }
};