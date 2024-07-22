class Solution {
public:
    bool dfs(int i, int j, int k, vector<vector<char>> &board, string word){
        int m = board.size();
        int n = board[0].size();

        if(word.size() == k){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[k]){
            return false;
        }
        char c = board[i][j];
        board[i][j] = '_';

        bool ans = dfs(i+1,j,k+1,board,word) || dfs(i,j+1,k+1,board,word) ||
                    dfs(i,j-1,k+1,board,word) || dfs(i-1,j,k+1,board,word);

        board[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(board[i][j] == word[0] && dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};