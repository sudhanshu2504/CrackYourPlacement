class Solution {
public:
    int getOnes(int n,int  m,vector<vector<int>>&board,int i,int j){
        int ones =0;
        if(i-1 >=0 && j-1>=0){
            if(board[i-1][j-1] ==1 ){
                ones++;
            }
        }
        if(i-1 >=0 && j+1 <m){
            if(board[i-1][j+1] ==1 ){
                ones++;
            } 
        }
        if(j-1 >= 0){
            if(board[i][j-1] ==1 ){
                ones++;
            }
        }
        if(j+1<m ){
            if(board[i][j+1] ==1 ){
                ones++;
            }
        }
        if(i+1<n && j+1<m){
            if(board[i+1][j+1] ==1 ){
                ones++;
            }
        }
        if(i+1<n){
            if(board[i+1][j] ==1 ){
                ones++;
            }
        }
        if(i+1<n && j-1>=0){
            if(board[i+1][j-1] ==1 ){
                ones++;
            }
        }
        if(i-1>=0){
            if(board[i-1][j] ==1 ){
                ones++;
            }
        }
        return ones;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int ones = getOnes(n,m,board,i,j);
                if(board[i][j] == 0){
                    if(ones == 3){
                        ans[i][j] = 1;
                    }
                }else{
                    if(ones == 2 || ones == 3){
                        ans[i][j] = 1;
                    }
                }
            }
        }
        board = ans;
    }
};