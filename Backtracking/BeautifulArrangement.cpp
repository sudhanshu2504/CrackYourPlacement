class Solution {
public:
    int solve(vector<bool> visited, vector<int>&nums,int index, int n){
        if(index == n+1){
            return 1;
        }
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(visited[nums[i]] == false && (nums[i] % index ==0 || index % nums[i] == 0)){
                visited[nums[i]] = true;
                ans += solve(visited, nums,index+1,n);
                visited[nums[i]] = false;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1,false);
        vector<int> nums;
        for(int i=1 ; i<=n ; i++){
            nums.push_back(i);
        }
        return solve(visited,nums,1,n);
    }
};