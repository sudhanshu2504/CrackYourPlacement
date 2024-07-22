class Solution {
public:
    string printDuplicate(string s) {
        map<char, int> count;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }
        for (auto it : count) {
            if (it.second > 1){
                ans += it.first;
            }
        }
        return ans;
    }
};