class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    map<int,int> m1;
    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i]>0){
            m1[nums[i]]++;
        }
    }
    int count = 1;
    for(auto x: m1){
        if(x.first == count){
            count++;
        }else{
            break;
        }
    }
    return count;
    }
};