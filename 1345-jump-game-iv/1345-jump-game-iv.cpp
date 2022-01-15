class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size() ; 
        if(n <= 2){ //corner cases
            return n - 1 ; 
        }
        unordered_map<int , vector<int>> samevals ; // to store indexes where a[i] == a[j] 
        for(int i = 0 ; i < n ; i++){
            samevals[a[i]].push_back(i) ; 
        }
        vector<bool> vis(n , 0) ; 
        queue<pair<int,int>> q ;
        q.push({0 , 0}) ;
        vis[0] = 1 ; 
        while(!q.empty()){
            auto node = q.front() ; 
            q.pop() ;
            if(node.first == n - 1) return node.second ; 
            if(node.first > 0 && !vis[node.first - 1]){
                q.push({node.first - 1 , node.second + 1}) ;
                vis[node.first - 1] = 1 ; 
            }
            if(node.first < n - 1 && !vis[node.first + 1]){
                q.push({node.first + 1 , node.second + 1}) ;
                vis[node.first + 1] = 1 ; 
            }
            for(int &i : samevals[a[node.first]]){
                if(i != node.first && !vis[i]){
                    q.push({i , node.second + 1}) ;
                    vis[i] = 1 ; 
                }
            }
            samevals[a[node.first]].clear() ; 
        }
        return 0 ; 
    }
};