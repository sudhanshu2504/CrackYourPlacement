class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 0;

        for(int i=1 ; i<intervals.size() ; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(start == x && end == y){
                ans++;
            }else if(end>x){
                ans++;
                end = min(end,y);
            }else{
                end = y;
            }
        }
        return ans;
    }
};