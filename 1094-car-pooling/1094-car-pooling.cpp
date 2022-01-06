class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b){
        if(a[1] == b[1])    return a[2] < b[2] ; 
        else    return a[1] < b[1] ; 
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin() , trips.end() , comp) ; 
        int n = trips.size() ; 
        vector<int> capacity_at_dist(1010 , 0) ; 
        for(int i = 0 ; i < n ; i++){
            capacity_at_dist[trips[i][1] + 1] += trips[i][0] ;
            capacity_at_dist[trips[i][2] + 1] -= trips[i][0] ; 
        }
        for(int i = 1 ; i <= 1000 ; i++){
             capacity_at_dist[i] += capacity_at_dist[i - 1] ;
            if(capacity_at_dist[i] > capacity)  return false ; 
        }
        return true ; 
    }
};