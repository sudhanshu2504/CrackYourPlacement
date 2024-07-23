class Solution {
public:
    void solve(vector<string>& ans, string s, int open,int close){ // open,close - bracket required
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open > 0){
            solve(ans,s+'(',open-1,close+1);
        }
        if(close > 0){
            solve(ans, s+')', open, close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, 0);
        return ans;
    }
};