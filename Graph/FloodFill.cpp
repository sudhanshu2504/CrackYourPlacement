class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc,int old, int color, vector<vector<int>>& visited){
        if(sr>=image.size() || sc>=image[0].size() || sr<0 || sc<0 || visited[sr][sc] == 1 || image[sr][sc] == color || image[sr][sc] != old){
            return;
        }
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        helper(image,sr+1,sc,old,color,visited);
        helper(image,sr-1,sc,old,color,visited);
        helper(image,sr,sc+1,old,color,visited);
        helper(image,sr,sc-1,old,color,visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),-1));
        int old = image[sr][sc];
        helper(image,sr,sc,old,color,visited);
        return image;
    }
};