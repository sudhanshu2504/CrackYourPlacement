class Solution {
public:
    string simplifyPath(string path) {
        int i=0 , j=0;
        if(path[path.length()-1] != '/'){
            path.push_back('/');
        }
        vector<string> folder;
        while(j<path.length()){
            if(path[j] != '/'){
                j++;
            }
            else{
                string sub = path.substr(i,j-i);
                if(sub != "" && sub !="/." && sub != "/"){
                    folder.push_back(sub);
                    // cout<<sub<<","<<endl;
                }
                i=j;
                j++;
            }
        }
        for(int i=0 ; i<folder.size() ; i++){
            if(folder[i] == "/.."){
                folder.erase(folder.begin()+i);
                i--;
                if(i>=0){
                    folder.erase(folder.begin()+i);
                    i--;
                }
            }
        }
        string ans = "";
        for(int i=0 ; i<folder.size() ; i++){
            // cout<<i<<"->"<<folder[i]<<endl;
            if(folder[i] != "/" && folder[i] != "/."){
                ans += folder[i];
            }
        }
        if(ans == ""){
            return "/";
        }
        return ans;
    }
};