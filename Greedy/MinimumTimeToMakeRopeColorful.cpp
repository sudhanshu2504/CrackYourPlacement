class Solution {
public:
    int minCost(string c, vector<int>& nT) {
    int ans = 0;
    int temp = nT[0];
    for(int i=1 ; i<nT.size() ; i++){
        if( c[i-1] == c[i] ){
            ans += min(temp,nT[i]); // minimum rope removed
            temp = max(temp, nT[i]); // another rope left
        }else{
            temp = nT[i];
        }
    }
    return ans; //8+8
    }
};