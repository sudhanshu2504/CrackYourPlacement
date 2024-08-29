class Solution {
public:
    int minDeletions(string s) {
        map<int,int> data;
        set<int> freq;
        int ans = 0;
        
        for(int i=0 ; i<s.length() ; i++){
            data[s[i]]++;
        }
        for(auto & i:data){
            while(i.second != 0 && freq.count(i.second)){
                i.second--;
                ans++;
            }
            freq.insert(i.second);
        }
        return ans;
    }
};