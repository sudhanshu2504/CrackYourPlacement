class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& aP) {
        vector<int> ans(aP.size()+1);
        map<int,vector<int>> hash;
        for(int i=0 ; i<aP.size() ; i++){
            hash[aP[i][0]].push_back(aP[i][1]);
            hash[aP[i][1]].push_back(aP[i][0]);
        }

        int left = INT_MIN;
        int right = INT_MIN;
        for(auto &i : hash){
            if(i.second.size() == 1){
                if(left == INT_MIN){
                    left = i.first;
                }else{
                    right = i.first;
                }
            }
        }

        ans[0] = left;
        ans[aP.size()] = right;

        for(int i=1 ; i<ans.size()-1 ; i++){
           if (i < 2 || ans[i - 2] != hash[ans[i - 1]][0])
                ans[i] = hash[ans[i - 1]][0];
            else
            {
                ans[i] = hash[ans[i - 1]][1];
            } 
        }

        return ans;
    }
};