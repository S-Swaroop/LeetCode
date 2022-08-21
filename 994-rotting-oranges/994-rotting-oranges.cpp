class Node {
public:
    int x , y , rotting_time ;
    Node (int a , int b , int c) {
        x = a ;
        y = b ;
        rotting_time = c ;
    };
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        queue<Node> q ; 
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 2) {
                    q.push(Node(i , j , 0)) ;
                }
            }
        }
        int total_time = 0 ;
        while (!q.empty()) {
            auto node = q.front() ;
            q.pop() ;
            total_time = max(total_time , node.rotting_time) ;
            for (int i = 0 ; i < 4 ; i++) {
                if (isValid(node.x + dx[i] , node.y + dy[i] , grid)) {
                    grid[node.x + dx[i]][node.y + dy[i]] = 2 ;
                    q.push(Node(node.x + dx[i] , node.y + dy[i] , node.rotting_time + 1)) ;
                }
            }
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 1) {
                    return -1 ;
                }
            }
        }
        return total_time ;
    }
private: 
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    bool isValid (int x , int y , vector<vector<int>> &grid) {
        return (x >= 0 && y >= 0 && x < (int)grid.size() && y < (int)grid[0].size() && grid[x][y] == 1) ;
    }
};