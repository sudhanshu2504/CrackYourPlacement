class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> left(h.size(),h[0]);
        vector<int> right(h.size(),h[h.size()-1]);
        for(int i=1 ; i<h.size() ; i++){
            left[i] = max(left[i-1],h[i]);
        }
        for(int i=h.size()-2 ; i>=0 ; i--){
            right[i] = max(right[i+1],h[i]);
        }
        int ans = 0;
        for(int i=0 ; i<h.size() ; i++){
            ans += min(left[i],right[i]) - h[i];
        }
        return ans;
    }
};