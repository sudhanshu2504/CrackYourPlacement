class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long int product = 1;
        long long int zero = 0;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != 0){
                product = (long long int)product*nums[i];
            }else{
                zero++;
            }
        }
        
        vector<long long int> ans;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(zero == 1){
                if(nums[i] != 0){
                    ans.push_back(0);
                }else{
                    ans.push_back(product);
                }
            }
            else if(zero>1){
                ans.push_back(0);
            }
            else{
                ans.push_back((long long int)(product/nums[i]));
            }
        }
        return ans;
    }
};
