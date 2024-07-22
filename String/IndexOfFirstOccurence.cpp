class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle){
            return 0;
        }else if(haystack.length() < needle.length()){
            return -1;
        }
        for(int i=0 ; i<=haystack.length() - needle.length() ; i++){
            string sub = haystack.substr(i,needle.length());
            if(sub == needle){
                return i;
            }
        }
        return -1;
    }
};