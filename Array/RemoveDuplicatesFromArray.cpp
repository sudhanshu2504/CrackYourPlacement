class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        map<int,int> data;
        for(int i=0 ; i<nums.size() ; i++){
            data[nums[i]]++;
        }
        vector<int> expected;
        for(auto &i:data){
            expected.push_back(i.first);
        }
        nums = expected;
        return expected.size();
    }
};