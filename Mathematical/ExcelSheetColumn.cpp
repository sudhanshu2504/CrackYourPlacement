class Solution {
public:
    string convertToTitle(int colNumber) {
        string ans ;
        while(colNumber>0){
            colNumber--;
            char c = 'A' + colNumber % 26;
            ans = c + ans;
            colNumber /= 26;
        }
        return ans;
    }
};