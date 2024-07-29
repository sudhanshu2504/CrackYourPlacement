class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sc;
        stack<char> tc;

        for(int i=0 ; i<s.length() ; i++){
            if(s[i] != '#'){
                sc.push(s[i]);
            }else{
                if(!sc.empty()){
                    sc.pop();
                }
            }
        }
        for(int i=0 ; i<t.length() ; i++){
            if(t[i] != '#'){
                tc.push(t[i]);
            }else{
                if(!tc.empty()){
                    tc.pop();
                }
            }
        }
        s = "";
        t = "";
        while(!sc.empty()){
            char temp = sc.top();
            sc.pop();
            s += temp;
        }
        while(!tc.empty()){
            char temp = tc.top();
            tc.pop();
            t += temp;
        }
        return (s==t);
    }
};