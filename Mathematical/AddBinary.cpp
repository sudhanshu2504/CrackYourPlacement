class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        
        if(b.size() > a.size()) {swap(a,b);}
        while(b.size() < a.size()) {b = "0" + b;}
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
       
        int i=0;
        int carry = 0;

        while(i<a.length() && i<b.length()){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == 0){
                    ans += '0';
                }else{
                    ans += '1';
                }
                carry = 1;
            }
            else if(b[i] == '0' && a[i] == '0'){
                if(carry == 0){
                    ans += '0';
                }else{
                    ans += '1';
                    carry = 0;
                }
            }
            else if((a[i]=='1' && b[i]=='0') || (b[i]=='1' && a[i]=='0')){
                if(carry == 0){
                    ans += '1';
                }else{
                    ans += '0';
                }
            }
            i++;
        }
        if(carry == 1){
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};