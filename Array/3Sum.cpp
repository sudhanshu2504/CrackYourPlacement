class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, vector<vector<int>> >data;
        set<vector<int>> ans;
        for(int i=0 ; i<nums.size()-1 ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                int sum = nums[i]+nums[j];
                data[sum].push_back({i,j});
            }
        }
        for(int i=0 ; i<nums.size() ; i++){
            int s = nums[i]*(-1);
            if(data.find(s) != data.end()){
                for(auto &index : data[s]){
                    if(index[0] != i && index[1] != i){
                        vector<int> temp = {nums[i],nums[index[0]],nums[index[1]]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> finalAns;
        for(auto& i:ans){
            finalAns.push_back(i);
        }
        return finalAns;
    }
};