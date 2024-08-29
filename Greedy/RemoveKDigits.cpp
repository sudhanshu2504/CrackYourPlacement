class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k){
            return "0";
        }
        stack<char> st;
        st.push(num[0]);
        
        for(int i=1 ; i<num.length() ; i++){
            while((!st.empty() && st.top()>num[i]) && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        if(k>0) {
            ans.erase(0,k);
        }
        reverse(ans.begin(),ans.end());
        while(ans[0] == '0'){
            if(ans == "0"){
                return ans;
            }
            ans = ans.substr(1);
        }
        return ans;
    }
};