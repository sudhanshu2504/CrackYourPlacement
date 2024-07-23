class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>> data;
        vector<vector<string>> ans;
        for(int i=0 ; i<string_list.size() ; i++){
            string temp = string_list[i];
            sort(temp.begin(),temp.end());
            data[temp].push_back(string_list[i]);
        }
        for(auto &i:data){
            ans.push_back(i.second);
        }
        return ans;
    }
};