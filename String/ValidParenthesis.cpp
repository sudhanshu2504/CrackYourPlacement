class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}' || st.size()%2 == 1){
            return false;
        }
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(s[i] == ')'){
                    char temp = st.top();
                    st.pop();
                    if(temp != '('){
                        return false;
                    }
                }
                if(s[i] == ']'){
                    char temp = st.top();
                    st.pop();
                    if(temp != '['){
                        return false;
                    }
                }
                if(s[i] == '}'){
                    char temp = st.top();
                    st.pop();
                    if(temp != '{'){
                        return false;
                    }
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};