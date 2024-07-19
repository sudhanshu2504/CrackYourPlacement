class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m1;
        for(int i=0 ; i<nums.size() ; i++){
            m1[nums[i]]++;
        }
        int i=0;
        for(auto x:m1){
            int a = x.first;
            int b = x.second;
            for(int j=0 ; j<b ; j++){
                nums[i] = a;
                i++;
            }
        }
    }
};