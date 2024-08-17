class Solution {
public:
    void solve(vector<vector<int>> &ans, vector <int> temp , int n, int k , int i){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i ; j<n+1 ; j++){
            temp.push_back(j);
            solve(ans,temp,n,k,j+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
       vector <vector<int>>ans;
       vector <int> temp;
       
       solve(ans,temp,n,k,1);
       return ans; 
    }
};