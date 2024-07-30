
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
    vector<int> ans;
    stack<int> t;

    for(int i=temp.size()-1 ; i>=0 ; i--){
        while(!t.empty() && temp[t.top()]<=temp[i]){
            t.pop();
        }

        if(t.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(t.top()-i);
        }
        t.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};