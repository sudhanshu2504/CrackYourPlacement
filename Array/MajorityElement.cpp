class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        map<int,int> freq;

        for(int i=0 ; i<nums.size() ; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > n){
                return nums[i];
            }
        }
        return -1;
    }
};