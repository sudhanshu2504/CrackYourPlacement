class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int> posi;
        for(int i=0 ; i<nums.size() ; i++){
            posi[nums[i]] = i+1;
        }
        return posi[target]-1;
    }
};