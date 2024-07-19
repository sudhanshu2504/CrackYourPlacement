class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = nums.size();
        int zero = 0;
        for(int i=0 ; i<count-zero ; i++){
            if(nums[i] == 0){
                zero++;
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                i--;
            }
        }
    }
};