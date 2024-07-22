class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string st = "";
      int min = 201;

      for(int i=0; i<strs.size(); i++){
        if(strs[i].length() < min){
          min = strs[i].length();
        }
      }
      
      for(int j=0; j<min ;j++){
          int count = 1;
          for(int k=1 ; k<strs.size(); k++){
            if(strs[k][j] != strs[k-1][j]){
                count = 0;
                break;
            }
          }
          if(count==1)
            {
                st+=strs[0][j];
            }
            else{
                break;
            }
              
      }

      return st;
    }
};