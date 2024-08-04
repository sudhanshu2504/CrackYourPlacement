class Solution {
public:
    string decodeString(string s) {
    stack<string> words;
    stack<int> freq;
    string ans;
    int num = 0;
    for(char c : s){
        if(isdigit(c)){
            num = num*10 + (c - '0');
        }else if( c == '['){
            words.push(ans);
            freq.push(num);
            ans = "";
            num = 0;
        }else if(c == ']'){
            string temp = ans;
            ans = words.top();
            words.pop();
            for(int i=freq.top() ; i>0 ; i--){
                ans += temp;
            }
            freq.pop();
        } else{
            ans += c;
        }
    }
    return ans;
    }
};
// num = 0;
// res = c
