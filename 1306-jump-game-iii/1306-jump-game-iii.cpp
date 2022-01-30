class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ; 
        vector<bool> vis(n , 0) ;
        return dfs(arr , start , vis) ;
    }
private: 
    bool isValid(int index , vector<int> &arr , vector<bool> &vis) {
        if(index < 0 || index >= arr.size() || vis[index])    return false ; 
        else    return  true ; 
    }
    bool dfs(vector<int> &arr , int start , vector<bool> &vis) {
        if (arr[start] == 0)    return true ; 
        vis[start] = 1 ;
        if (isValid(start + arr[start] , arr , vis)) {
            if (dfs(arr , start + arr[start] , vis)) {
                return true ; 
            }
        } 
        if (isValid(start - arr[start] , arr , vis)) {
            if (dfs(arr , start - arr[start] , vis)) {
                return true ; 
            }
        }
        return false ; 
    }
};