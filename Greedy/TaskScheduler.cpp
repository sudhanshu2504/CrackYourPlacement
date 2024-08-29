class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> task;
        map<char,int> lastDone;
        for(int i=0 ; i<tasks.size() ; i++){
            task[tasks[i]]++;
            lastDone[tasks[i]] = -1;
        }
        int intervals = 0;
        int maxi = 0;
        for(auto &i:task){
            maxi = max(maxi,i.second);
        }
        for(auto &i:task){
            if(i.second==maxi)intervals++;
        }
        int ans = ((maxi-1)*(n+1))+intervals;
        ans = max(ans,(int)tasks.size());
        return ans;
    }
};