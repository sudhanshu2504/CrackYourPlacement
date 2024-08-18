class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end =0;
        int ans = 0, maxi = 0;
        int size = s.length();
        map<char,int> f;

        while(end<size){
            f[s[end]]++;
            maxi = max(maxi, f[s[end]]);

            if( end-start+1-maxi > k){
                f[s[start]]--;
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;

    }
};