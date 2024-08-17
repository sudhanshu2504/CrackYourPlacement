class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>& candidates, vector<int>& current, int target , int index){
        if(target==0){
            st.insert(current);
            return;
        }
        if(0>target || index>=candidates.size()){
            return;
        }
        current.push_back(candidates[index]);
        solve(candidates,current,target-candidates[index],index+1);
        current.pop_back();
        while(index+1<candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }
        solve(candidates,current,target,index+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> sub;
        int sum = 0;
        solve(candidates,sub,target,0);

        vector<vector<int>> ans;
        for(auto &i:st){
            ans.push_back(i);
        }
        return ans;
    }
};