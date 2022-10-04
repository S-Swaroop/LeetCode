class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image ;
        }
        dfs(sr , sc , color , image) ;
        return image ;
    }
private:
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , 1 , 0 , -1} ;
    bool isValid (int x , int y , int startingColor , vector<vector<int>> &image) {
        return (x >= 0 && x < (int)image.size() && y >= 0 && y < (int)image[0].size() && image[x][y] == startingColor) ;
    }
    void dfs (int x , int y , int color , vector<vector<int>> &image) {
        int startingColor = image[x][y] ;
        image[x][y] = color ; 
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i] , startingColor , image)) {
                dfs(x + dx[i] , y + dy[i] , color , image) ;
            }
        }
    }
};