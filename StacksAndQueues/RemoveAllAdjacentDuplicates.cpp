class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        stack<pair<char,int>> st;
        st.push({'A',1});
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == st.top().first){
                st.push({s[i], st.top().second+1});
            }else{
                st.push({s[i],1});
            }
            if(st.top().second == k){
                int temp = k;
                while(temp--){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans.substr(1);
    }
};