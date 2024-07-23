class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int temp = 0;
        char sign = '+';

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                temp = 10*temp + int(s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1){
                if(sign == '+'){
                    st.push(temp);
                }
                else if(sign == '-'){
                    st.push(-temp);
                }
                else{
                    int num;
                    if(sign == '*'){
                        num = st.top() * temp;
                    }
                    else{
                        num = st.top() / temp;
                    }
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                temp = 0; 
            }
            
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};