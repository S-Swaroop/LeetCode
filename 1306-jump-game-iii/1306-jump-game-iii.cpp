class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ; 
        return bfs(arr , start) ;
    }
private: 
    bool isValid(int index , vector<int> &arr , vector<bool> &vis) {
        if(index < 0 || index >= arr.size() || vis[index])    return false ; 
        else    return  true ; 
    }
    bool bfs(vector<int> &arr , int start) {
        if (arr[start] == 0)    return true ; 
        int n = arr.size() ;
        vector<bool> vis(n , 0) ;
        vis[start] = 1 ;
        queue<int> q ; 
        q.push(start) ;
        while (!q.empty()) {
            int index = q.front() ; 
            q.pop() ; 
            if (arr[index] == 0)    return true ; 
            if (isValid(index + arr[index] , arr , vis)) {
                q.push(index + arr[index]) ;
                vis[index + arr[index]] = 1 ;
            } 
            if (isValid(index - arr[index] , arr , vis)) {
                q.push(index - arr[index]) ;
                vis[index - arr[index]] = 1 ;
            }
        }
        return false ; 
    }
};