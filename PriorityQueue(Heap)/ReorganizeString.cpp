class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> freq;
        for(int i=0 ; i<s.length() ; i++){
            freq[s[i]]++;
        }
        for(auto &i:freq){
            pq.push({i.second,i.first});
        }
        string ans = "";
        while(pq.size()>=2){
            auto [f1,c1] = pq.top();
            pq.pop();
            auto [f2,c2] = pq.top();
            pq.pop();
            
            ans += c1;
            ans += c2;

            f1--;f2--;

            if(f1>0){
                pq.push({f1,c1});
            }
            if(f2>0){
                pq.push({f2,c2});
            }
        }
        while(!pq.empty()){
            auto [f,c] = pq.top();
            pq.pop();
            if(f>1){
                return "";
            }
            ans +=c;
        }
        return ans;
    }
};